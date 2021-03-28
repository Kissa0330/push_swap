function main(input) {
  let splitInput = input.split("\n");
  let number = splitInput[0].split(" ");
  let x = number[2];
  let y = number[3];
  let target = splitInput[x].split("")[y];
  let answer = 0;
  // 横列の右側の処理
  for (let i = 0; i < number[0] - x; i++) {
    let anotherY = Number(y) + Number(i);
    let target1 = splitInput[x].split("")[anotherY];
    if (target1 === ".") {
      answer = answer + 1;
    } else if (target1 === "#") {
      break;
    }
  }
  // 横列の左側の処理
  for (let i = 0; i < -(-Number(number[0]) + Number(x)); i++) {
    let anotherY = Number(y) - Number(i);
    let target1 = splitInput[x].split("")[anotherY];
    if (target1 === ".") {
      answer = answer + 1;
    } else if (target1 === "#") {
      break;
    }
  }
  // 縦列の右側の処理
  for (let i = 0; i < number[1] - y; i++) {
    let anotherX = Number(x) + Number(i);
    let target1 = splitInput[anotherX].split("")[y];
    if (target1 === ".") {
      answer = answer + 1;
    } else if (target1 === "#") {
      break;
    }
  }
  // 横列の左側の処理
  for (let i = 0; i < -(-Number(number[0]) + Number(y)); i++) {
    let anotherX = Number(x) - Number(i);
    let target1 = splitInput[anotherX].split("")[y];
    if (target1 === ".") {
      answer = answer + 1;
    } else if (target1 === "#") {
      break;
    }
  }
  // 重なってる部分をマイナス
  answer = answer - 2;
  console.log(answer);
}
main(require("fs").readFileSync("/dev/stdin", "utf8"));
