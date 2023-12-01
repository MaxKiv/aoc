use std::io;

const DIGITS: [&str; 9] = [
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
];

fn main() {
    let mut answer_a : u32 = 0;

    println!("Part A: {}", answer_a);

    for line in io::stdin().lines() {
        let cur = solve_a(line.as_ref().unwrap());
        println!("{}: {}", line.unwrap(), cur);
        answer_a += cur;
    }

    println!("Part B: {}", answer_b);
    let mut answer_b : u32 = 0;
}

fn solve_a(line : &str) -> u32{
    line.chars().rev().find_map(|c| c.to_digit(10)).unwrap() + 10 * line.chars().find_map(|c| c.to_digit(10)).unwrap()
}

fn solve_b(line : &str) -> u32{
    let test : String = String::from("asdstwo1908fivesdf");
    test.chars()
        .enumerate()
        .filter(|&(_, c)| c == DIGITS.iter().chars().next())
        .peekable( // somehow get next 5 chars "tok" and check for DIGITS.iter().any(|s|
    // s.contains(tok)
        )

}
