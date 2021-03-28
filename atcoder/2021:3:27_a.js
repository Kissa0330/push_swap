function main(input) {
  let inputSplit = input.split("");
  let inputAfter = inputSplit[1] + inputSplit[2] + inputSplit[0];
  console.log(inputAfter);
}
main(require("fs").readFileSync("/dev/stdin", "utf8"));
