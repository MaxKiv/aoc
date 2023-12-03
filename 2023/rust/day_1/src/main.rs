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
    let input: Vec<String> = io::stdin().lines().filter_map(Result::ok).collect::<Vec<String>>();

    println!("Part one: {}", part_1(&input));
    println!("Part two: {}", part_2(&input));
}

fn part_1(input: &Vec<String>) -> u32 {
    input.iter().map(|line| parse_line_1(line)).sum()
}

fn part_2(input: &Vec<String>) -> u32 {
    input.iter().map(|line| parse_line_2(line)).sum()
}

fn parse_line_1(line: &str) -> u32 {
    line.chars()
        .rev()
        .find_map(|c| c.to_digit(10))
        .expect(format!("No digit found on line {}", line).as_str())
        + 10 * 
    line
        .chars()
        .find_map(|c| c.to_digit(10))
        .expect(format!("No digit found on line {}", line).as_str())
}

fn parse_line_2(line: &str) -> u32 {
    let last =
        (0..line.len())
            .rev()
            .find_map(|i| is_slice_a_digit(&line[i..]))
            .expect( "No first digit found on line: {line}",);
    let first = (0..line.len())
        .find_map(|i| is_slice_a_digit(&line[i..]))
        .expect( "No second digit found on line {line}",);
    // println!("{}: {} {}", line, first, last);
    10 * first + last
}

fn is_slice_a_digit(slice: &str) -> Option<u32> {
    DIGITS.iter()
        .enumerate()
        .find(|(_, digit)| slice.starts_with(*digit))
        .map(|(i, _)| i as u32 + 1)
        .or_else(|| slice.chars().next().unwrap().to_digit(10))
}

