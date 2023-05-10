function solution(scanner) {
    const finalResult = [];
    const N = scanner.readInt();
    const root = {
        id: '__root',
        class: [],
        parent: null,
        child: []
    };
    const idMap = new Map();
    const classMap = new Map();
    idMap.set('__root', root);
    const stack = ['__root'];
    for (let i = 0; i < N; i++) {
        const line = scanner.readLine();
        if (line.startsWith('<d')) {
            const [_id, classes] = parseDiv(line);
            console.log(_id, classes);
            const obj = {
                id: _id,
                class: classes,
                parent: stack[stack.length - 1],
                child: []
            };
            for (const className of classes) {
                if (classMap.has(className)) {
                    const arr = classMap.get(className);
                    arr.push(_id);
                    classMap.set(className, arr);
                } else {
                    classMap.set(className, [_id]);
                }
            }
            idMap.get(stack[stack.length - 1]).child.push(obj);
            stack.push(_id);
            idMap.set(_id, obj);
        } else if (line.startsWith('</')) {
            stack.pop();
        }
    }
    console.log('root', root);
    console.log('idMap', idMap);
    console.log('classMap', classMap);
    
    // 맨 아래 자식으로부터의 높이 구하기
    const heightQueue = [...idMap.keys()].filter(_ => idMap.get(_).child.length === 0).map(_ => [_, 1]);
    console.log('heightQueue', heightQueue);
    while (heightQueue.length > 0) {
        const curItem = heightQueue.shift();
        const curID = curItem[0];
        const curHeight = curItem[1];
        if (!idMap.get(curID).height || curHeight > idMap.get(curID).height) {
            idMap.get(curID).height = curHeight;
        }
        if (idMap.get(curID).parent) {
            heightQueue.push([idMap.get(curID).parent, curHeight + 1]);
        }
    }
    console.log('idMap (After adding height)', idMap);

    const M = scanner.readInt();

    for (let i = 0; i < M; i++) {
        const query = scanner.readLine().split(' ');
        console.log('query:', query);
        let result = getClassMatchedIDs(query[0], ['__root']);
        let isDirect = false;
        for (let qd = 1; qd < query.length; qd++) {
            if (query[qd] != '>') {
                // 직속 자식 선택자가 아닌 경우의 처리.. 현재 부모의 자식들을 모두 구해서 넘겨줌.
                let pResult = getClassMatchedIDs(query[qd], result, isDirect);
                if (!isDirect) {
                    // 높이로 필터링 (남은 커맨드 수 참고)
                    // let cmdLeft = 0;
                    // for (let _i = qd; _i < query.length; _i++) {
                    //     if (query[_i] === '>') break;
                    //     cmdLeft++;
                    // }
                    // console.log('cmdLeft', cmdLeft);
                    // pResult = pResult.filter(_ => {
                    //     // console.log('compare height for ', _, idMap.get(_).height);
                    //     if (idMap.get(_).height >= cmdLeft) return true;
                    //     return false;
                    // });
                } else {
                    // 부모가 가지고 있는 녀석만 포함되도록 조정
                    pResult = pResult.filter(_ => {
                        if (result.indexOf(_) > -1) return true;
                        return false;
                    });
                }
                result = pResult;
                isDirect = false;
            } else {
                // 직속 자식 선택자가 왔을 때의 처리.. 현재 result에 있는 직속 자식들만 남긴다.
                let children = [];
                result.forEach(_ => {
                    const curItem = idMap.get(_);
                    children = [...children, ...curItem.child.map(_ => _.id)];
                });
                result = children;
                isDirect = true;
            }
            // console.log('filtered #', qd, result);
            console.log('filtered #', qd, ', remained:', result.length);
            if (result.length === 0) break;
        }

        console.log('query Result:', result.length + ' ' + result.join(' '));
        finalResult.push(result.length + ' ' + result.join(' '));
    }

    return finalResult.join('\n');

    function getClassMatchedIDs(q, parentIDs, isDirect) {
        let children;
        if (isDirect) {
            children = [...idMap.keys()];
        } else {
            // parentIDs의 자식들의 리스트를 구한다.
            children = new Set();
            parentIDs.forEach(_ => {
                const curItem = idMap.get(_);
                children = new Set([...children, ...curItem.child.map(_ => _.id)]);
            });
            const visited = new Set(children);
            const queue = [...children];
            while (queue.length > 0) {
                // Children에 추가
                const cur = queue.shift();
                children.add(cur);
                const curItem = idMap.get(cur);
                const curChilds = curItem.child.map(_ => _.id);
                for (let i = 0; i < curChilds.length; i++) {
                    if (!visited.has(curChilds[i])) { // 방문하지 않았으면 추가
                        queue.push(curChilds[i]);
                        visited.add(curChilds[i]);
                    }
                }
            }
            // console.log('baseChildren', children);
        }

        // 자식들의 리스트를 베이스로, 검색 시작한다.
        let result = [...children];

        const classes = q.split('.');
        classes.splice(0, 1); // 처음 공백 제거
        for (let i = 0; i < classes.length; i++) {
            let pResult = classMap.get(classes[i]);
            // console.log(classes[i], pResult);
            pResult = pResult.filter(_ => {
                if (result.indexOf(_) > -1) return true;
                return false;
            });
            result = pResult;
        }
        // console.log('classFindResult', result);
        return result;
    }

    function parseDiv(str) {
        let id = str;
        id = id.replace(/.+id=\'/, '');
        id = id.replace(/\'.+/, '');

        let classes = str;
        classes = classes.replace(/.+class=\'/, '');
        classes = classes.replace(/\'.+/, '');

        return [id, classes.split(' ')];
    }
}

/* 형태 구성
 [{
    id: 'a',
    class: ['banana', 'mango'],
    child: [{
        id: 'b',
        class: ['...'],
        child: [],
        parent: 'a' 위쪽..
    }],
    parent: root(순환)
}, {

}]

*/

/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
const scanner = {
    readInt: () => {
        return parseInt(__lineDB[__lineIdx++], 10);
    },
    readLine: () => {
        return __lineDB[__lineIdx++];
    }
};
let __lineDB = [];
let __lineIdx = 0;
const isDebug = process.argv[2] === 'readizDebug';
if (!isDebug) {
    global.console = {
        log: () => {},
        warn: () => {},
        info: () => {},
        debug: () => {},
        error: () => {}
    };
    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.on('line', (line) => {
        __lineDB.push(line);
    });
    rl.on('close', () => {
        process.stdout.write(solution(scanner) + '\n');
    });
} else {
    __lineDB = require('fs').readFileSync(process.argv[1].replace('.js', '_input.txt')).toString().split('\n');
    while (__lineIdx < __lineDB.length) {
        process.stdout.write('--------------------------------------------\n');
        process.stdout.write('New Start + Log\n');
        process.stdout.write('--------------------------------------------\n');
        const start = __lineIdx;
        const answer = solution(scanner);
        const end = __lineIdx;
        process.stdout.write('----------------------\n');
        process.stdout.write('Input\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(__lineDB.slice(start, end).join('\n') + '\n');
        process.stdout.write('----------------------\n');
        process.stdout.write('Answer\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(answer + '\n');
    }
}


/*
CSS 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
10 초	256 MB	157	6	6	35.294%
문제
오늘날 많이 사용되고 있는 HTML 문서는 계층 구조를 가지는 형식이다. 이 문서는 '요소'라 불리는 것들로 구성되어 있으며, 요소는 이름과 함께 특정 '속성'들을 가지고, 또 다른 요소들을 포함할 수도 있다. 여기에서는 div 요소로만 구성되어 있는 HTML 문서를 사용한다고 가정하자. 명확하게, 각 문서는 아래와 같은 형태의 라인들로 구성되어 있다.

<div id=’name’ class=’class1 class2 . . . classK’> 요소의 시작
...                                                요소의 내용
</div>                                             요소의 끝
따라서, 한 개의 요소는 그 시작을 나타내는 줄과, 그 끝을 나타내는 줄, 그리고 그 사이가 비어 있거나, 혹은 그 사이에 또 다른 요소를 계속해서 포함할 수 있는 요소가 한 개 혹은 여러 개 존재하는 내용으로 구성되어 있다. 문서 또한 여러 요소의 집합으로 구성되어 있으며, 그 중 일부는 또 다른 요소를 포함할 수도 있다. 추가적으로 요소를 정의하기 위한 사항들은 다음과 같다.

요소의 이름(id)은 영문 알파벳 소문자로 구성되어 있다. 이름은 문서에서 해당 요소를 하나밖에 없는 것으로 정의하며, 다른 요소와 같은 이름을 사용할 수 없다.
요소의 각 클래스(class) 역시 영문 알파벳 소문자로 구성되며, 요소의 초기 목록에 포함된 클래스가 있다면, 그 요소가 해당 클래스에 속한다고 할 수 있다. 각 요소는 하나 이상의 서로 다른 클래스에 속할 수 있다. 서로 다른 요소가 같은 클래스들에 속하는 것 역시 가능하다.
요소를 나타내는 줄에서 공백이 올 수 있는 곳은 id 바로 앞에 1개, class 바로 앞에 1개 그리고 각각의 클래스 사이, 즉, 인접한 두 클래스 사이에 1개다.
만약 요소 E가 요소 F의 내용 (즉, 시작을 나타내는 줄과, 끝을 나타내는 줄 사이의 어느 곳이든) 에 작성되어 있다면, 우리는 F가 E를 포함하고 있다고 할 수 있고, 다시 말해, E가 F에 포함되어 있다고 할 수 있다.

만약 요소 F가 E에 포함되어 있으며, 'F를 포함하고 E에 포함된' G라는 요소가 없다면, E는 F의 부모라 할 수 있다.

CSS는 웹브라우저에서 HTML 요소들이 보여질 때 그 요소들의 생김새와 형태를 기술하기 위해 사용되는 스타일 시트 언어다. 이 언어의 중요한 부분은 선택자와 분류자(classifier)다. 분류자는 점(.)으로 시작되며, 점(.)으로 구분되는 하나 이상의 클래스가 나열되는 형태를 가진다. 다시 말하지만 클래스는 영문 소문자 알파벳으로만 이루어져 있다. 분류자의 몇 가지 예를 들면 다음과 같다. ".banana.apple", ".banana", ".apple.banana.mango". 이 분류자들은 순서대로 각각 2개, 1개, 3개의 클래스로 이루어져 있다. 우리는 분류자에 나열된 모든 클래스에 속한 HTML 요소는 그 분류자에 속한다고 한다.

선택자는 하나 이상의 분류자로 구성되며, 인접한 두 분류자는 공백, 오른 꺽쇠(" > "), 공백 문자열로 구분된다. HTML 요소는 재귀적으로 정의된 아래와 같은 방법으로 선택자에 의해 선택된다.

선택자 S가 딱 하나의 분류자 k로 구성되었다면, k에 해당하는 요소는 S에 해당한다.
선택자 S가 'T k'의 형태이며 T가 선택자, k가 분류자라면, k에 해당하는 요소 E가 T에 해당하는 요소 F에 포함되어 있다면(직접 포함일 필요는 없다), E는 S에 해당한다.
선택자 S가 'T > k'의 형태이며 T가 선택자, k가 분류자라면, k에 해당하는 요소 E의 부모 F가 T에 해당할 경우, E가 S에 해당한다.
N 줄로 구성된 문서와 M 개의 선택자가 주어질 때, 각 선택자에 해당하는 모든 요소의 이름을 출력하는 프로그램을 작성하시오. 각각의 선택자에 대해 출력은 주어진 문서 상에 나타나는 순서와 반드시 일치해야 한다.

입력
입력의 첫 줄에는 짝수 정수, N(2 ≤ N ≤ 10 000)이 주어지며, 전체 문서의 줄 수를 나타낸다.

이어지는 N개의 줄에 문서의 내용이 주어진다. 각 줄은 위에서 설명한 대로 한 요소의 시작이거나 끝에 해당한다.

그 다음 줄에는 선택자의 개수 M(1 ≤ M ≤ 5)이 정수로 주어진다.

그 다음 M개 줄에는 각각의 선택자가 주어진다.

입력되는 데이터의 모든 요소의 이름과 클래스는 영문 알파벳 소문자로만 구성되며 20자를 넘지 않는다.

추가적으로, 입력 데이터의 각 줄은 5,000 글자를 넘지 않으며, 입력에 포함된 모든 줄의 길이를 합해도 5,000,000 글자를 넘지 않는다.

출력
입력 데이터의 각 선택자마다 한 줄을 출력한다. 먼저 그 선택자에 해당하는 요소의 개수를 출력하고, 문서에 기술된 순서대로 요소의 이름(id)을 출력한다.

예제 입력 1 
22
<div id='a' class='banana mango'>
<div id='b' class='orange'>
<div id='c' class='banana'>
<div id='d' class='apple mango orange'>
<div id='e' class='orange'>
</div>
</div>
</div>
</div>
<div id='f' class='orange apple'>
<div id='g' class='apple'>
<div id='h' class='orange apple'>
<div id='i' class='banana'>
</div>
</div>
</div>
<div id='j' class='banana'>
</div>
</div>
</div>
<div id='k' class='glupo voce daj mi sarme'>
</div>
5
.banana
.banana > .sarme
.banana > .orange > .banana
.banana .apple.orange > .orange
.mango > .orange .banana
예제 출력 1 
4 a c i j
0
2 c j
1 e
3 c i j
*/
