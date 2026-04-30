use std::fs::read_to_string;

mod jolt;
use jolt::*;

fn main() {
    let content = read_to_string("../input.txt").unwrap();
    let lines = content.lines();
    let mut max_joltage = 0;
    for line in lines {
        let line_joltage = get_max_joltage(line, 12);
        max_joltage = max_joltage + line_joltage;
        // print!("{} ", line);
        print!("{}\n", line_joltage);
    }
    println!("{}", max_joltage);
}
