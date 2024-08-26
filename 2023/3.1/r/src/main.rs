use std::fs::read_to_string;

mod parse;
use parse::*;

fn main() {
    let content = read_to_string("../input.txt").unwrap();
    let mut p = 0;
    let mut lines = vec![];
    for line in content.lines() {
        lines.push((p, line));
        p = p + 1;
    }
    let lines2 = lines.clone();
    let sym_table = parse_symbol_table(lines);
    let num_table = parse_part_table(lines2);
    let part_num_table = num_table
        .iter()
        .map(|l| l.1.iter().filter(|m| num_is_part_num(l.0, m, &sym_table)));

    let sum = part_num_table
        .map(|c| c.map(|m| m.0.parse::<u32>().ok().unwrap()).sum::<u32>())
        .sum::<u32>();

    println!("{}", sum);
}
