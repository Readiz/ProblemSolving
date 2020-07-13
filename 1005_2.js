const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
let isEnteringBuildingTime = false;
let isEnteringDepTree = false;
let numberOfBuildings;
let buildingTimes = [];
let depTree = [];
rl.on('line', (line) => {
    if (isFirst) { isFirst = false; return; } // First Input => No use!
    const inputNumbers = line.split(' ').map(item => parseInt(item));
    
    if (isEnteringDepTree) {
        if (inputNumbers.length == 2) {
            depTree[inputNumbers[1]].push(inputNumbers[0]);
            console.log(depTree);
        } else if (inputNumbers.length == 1) {
            isEnteringDepTree = false;

            // Start Calculating
            const targetBuildingNum = inputNumbers[0];
            // Initialize overallBuildTime with last building value.
            let overallBuildTime = buildingTimes[targetBuildingNum];
            let nextTargets = [...depTree[targetBuildingNum]];
            
            while (nextTargets.length >= 1) {
                console.log('StartSum: ' + overallBuildTime);
                console.log('To build ' + targetBuildingNum + ', build: ', nextTargets);
                overallBuildTime += Math.max(...buildingTimes.filter((item, idx) => nextTargets.includes(idx)));
                console.log('CurrentSum: ' + overallBuildTime);

                // building next Loop...
                let tmpNext = [];
                for (item of nextTargets) {
                    tmpNext = [...tmpNext, ...depTree[item]];
                }
                tmpNext = [...new Set(tmpNext)]; // Delete Duplicate

                console.log('Next Loop: ', tmpNext);
                nextTargets = tmpNext;
            }
            console.log('Final overallBuildTime: ', overallBuildTime);
            console.log(overallBuildTime);
        }
    }

    if (isEnteringBuildingTime) {
        isEnteringBuildingTime = false;
        isEnteringDepTree = true;
        buildingTimes = [-1, ...inputNumbers];
        console.log(buildingTimes);
    }

    if (inputNumbers.length == 2 && !isEnteringDepTree && !isEnteringBuildingTime) {
        isEnteringBuildingTime = true;
        numberOfBuildings = inputNumbers[0];
        depTree = [];
        for (let i = 0; i <= numberOfBuildings; i++) {
            depTree.push([]);
        }
        buildingTimes = [];
        console.log('NumberOfBuildings: ' + numberOfBuildings);
    }
});

/*
문제 
서기 2012년! 드디어 2년간 수많은 국민들을 기다리게 한 게임 ACM Craft (Association of Construction Manager Craft)가 발매되었다.
이 게임은 지금까지 나온 게임들과는 다르게 ACM크래프트는 다이나믹한 게임 진행을 위해 건물을 짓는 순서가 정해져 있지 않다.
즉, 첫 번째 게임과 두 번째 게임이 건물을 짓는 순서가 다를 수도 있다.
매 게임시작 시 건물을 짓는 순서가 주어진다.
또한 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 Delay가 존재한다.
 
위의 예시를 보자.
이번 게임에서는 다음과 같이 건설 순서 규칙이 주어졌다.
1번 건물의 건설이 완료된다면 2번과 3번의 건설을 시작할수 있다. (동시에 진행이 가능하다)
그리고 4번 건물을 짓기 위해서는 2번과 3번 건물이 모두 건설 완료되어야지만 4번건물의 건설을 시작할수 있다.
따라서 4번건물의 건설을 완료하기 위해서는 우선 처음 1번 건물을 건설하는데 10초가 소요된다.
그리고 2번 건물과 3번 건물을 동시에 건설하기 시작하면 2번은 1초뒤에 건설이 완료되지만 아직 3번 건물이 완료되지 않았으므로 4번 건물을 건설할 수 없다.
3번 건물이 완성되고 나면 그때 4번 건물을 지을수 있으므로 4번 건물이 완성되기까지는 총 120초가 소요된다.
프로게이머 최백준은 애인과의 데이트 비용을 마련하기 위해 서강대학교배 ACM크래프트 대회에 참가했다!
최백준은 화려한 컨트롤 실력을 가지고 있기 때문에 모든 경기에서 특정 건물만 짓는다면 무조건 게임에서 이길 수 있다.
그러나 매 게임마다 특정건물을 짓기 위한 순서가 달라지므로 최백준은 좌절하고 있었다.
백준이를 위해 특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램을 작성해주자.

입력 
첫째 줄에는 테스트케이스의 개수 T가 주어진다.
각 테스트 케이스는 다음과 같이 주어진다.
첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다) 
둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다. 
셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다) 
마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다.

출력 
건물 W를 건설완료 하는데 드는 최소 시간을 출력한다.
편의상 건물을 짓는 명령을 내리는 데는 시간이 소요되지 않는다고 가정한다.
모든 건물을 지을 수 없는 경우는 없다.

제한 
2 ≤ N ≤ 1000
1 ≤ K ≤ 100000
1 ≤ X,Y,W ≤ N
0 ≤ D ≤ 100000

예제 입력 1 
2
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
8 8
10 20 1 5 8 7 1 43
1 2
1 3
2 4
2 5
3 6
5 7
6 7
7 8
7

예제 출력 1
120
39

예제 입력 2
5
3 2
1 2 3
3 2
2 1
1
4 3
5 5 5 5
1 2
1 3
2 3
4
5 10
100000 99999 99997 99994 99990
4 5
3 5
3 4
2 5
2 4
2 3
1 5
1 4
1 3
1 2
4
4 3
1 1 1 1
1 2
3 2
1 4
4
7 8
0 0 0 0 0 0 0
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
7

예제 출력 2
6
5
399990
2
0
*/