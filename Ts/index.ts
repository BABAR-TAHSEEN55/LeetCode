const NaturalNumber = (n: Number): void => {
  for (let i = 1; i <= n; i++) {
    console.log(i);
  }
};

const NaturalNumberSum = (n: Number): void => {
  let sum = 0;
  for (let i = 0; i <= n; i++) {
    sum += i;
  }
  console.log(sum);
};
NaturalNumber(10);
NaturalNumberSum(10);

