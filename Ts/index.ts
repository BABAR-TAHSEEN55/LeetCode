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

const PerfectNumber = (n) => {
  let sum = 1;
  for (let i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;
      if (n / i != i) {
        sum += n / i;
      }
    }
  }
  return sum == n;
};

const AllNum = (start, end) => {
  for (let i = start; i <= end; i++) {
    if (PerfectNumber(i)) {
      console.log("PN");
      console.log(i);
    }
  }
};

const PrimeNumber = (n) => {
  let count = 0;
  for (let i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      if (n / i != i) {
        count++;
      }
    }
  }
  count == 2 ? console.log("Rn") : console.log("Nrn");
};
// NaturalNumberSum(10);
// AllNum(6, 500);
//
PrimeNumber(9);
