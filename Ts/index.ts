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

const PrimeNumber = (n): boolean => {
  if (n < 2) return;
  let count = 0;
  for (let i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      if (n / i != i) {
        count++;
      }
    }
  }
  return count === 2;
};
const RunAll = (start, end) => {
  for (let i = start; i <= end; i++) {
    if (PrimeNumber(i)) {
      console.log(i);
    }
  }
};
const PrevPrime = (n) => {
  for (let i = n - 1; i >= 2; i--) {
    if (PrimeNumber(i)) {
      console.log(i);
      return;
    }
  }
};
const Gcd = (a: number, b: number): number => {
  while (a > 0 && b > 0) {
    a > b ? (a %= b) : (b %= 10);
  }
  return a === 0 ? b : a;
};

const SumofDigits = (n: number): number => {
  let sum = 0;
  while (n > 0) {
    let digit = n % 10;
    n = Math.floor(n / 10);
    sum += digit;
  }
  return sum;
};
const StarPattern = (n: number) => {
  for (let i = 0; i <= n; i++) {
    for (let j = i; j < n; j++) {
      process.stdout.write("*");
    }
    console.log(" ");
  }
};
const Cube = (n: number) => {
  return n * n * n;
};
const PrintCube = (start: number, end: number) => {
  for (let i = start; i <= end; i++) {
    console.log(Cube(i));
  }
};
const StarPattern2 = (n: number) => {
  for (let i = 0; i <= n; i++) {
    for (let j = 0; j <= i; j++) {
      process.stdout.write(j.toString());
    }
    console.log(" ");
  }
};

const PyramidPatter = (n: number) => {
  for (let i = 0; i <= n; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      process.stdout.write(" ");
    }

    for (let j = 0; j < 2 * i + 1; j++) {
      process.stdout.write("*");
    }

    for (let j = 0; j < n - i - 1; j++) {
      process.stdout.write(" ");
    }
    console.log(" ");
  }
};
const ReversePatter = (n: number) => {
  for (let i = 0; i <= n; i++) {
    for (let j = 0; j < i; j++) {
      process.stdout.write(" ");
    }
    for (let j = 0; j < 2 * n - 2 * i - 1; j++) {
      process.stdout.write("*");
    }

    for (let j = 0; j < i; j++) {
      process.stdout.write(" ");
    }
    console.log(" ");
  }
};
// console.log(4 / 2);
// NaturalNumberSum(10);
// AllNum(6, 500);
PrintCube(1, 5);
// PrimeNumber(9);
// RunAll(2, 19);
// PrevPrime(10);
// console.log(Gcd(50, 100));
// console.log(SumofDigits(123));
// StarPattern(5);
// StarPattern2(5);
// PyramidPatter(4);
ReversePatter(5);
