use std::io;

fn main() {
    let mut answer_a : u32 = 0;
    let mut answer_b : u32 = 0;

    for line in io::stdin().lines() {
        answer_a = answer_a + solve_a(line.unwrap());
        println!("{}", answer_a);
    }

    println!("Part A: {}", answer_a);
    println!("Part B: {}", answer_b);
}

fn solve_a(line : String) -> u32{
    let a = line.chars().find_map(|c| c.to_digit(10)).unwrap();
    let b = line.chars().rev().find_map(|c| c.to_digit(10)).unwrap();
    return a + b

    line.chars().find_map(|c| c.to_digit(10)).unwrap() + line.chars().rev().find_map(|c| c.to_digit(10)).unwrap();
}
