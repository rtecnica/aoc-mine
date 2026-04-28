use std::fs::read_to_string;

mod divs;
use divs::*;

fn main() {
    let mut running_sum: u64 = 0;
    let content = read_to_string("../input.txt").unwrap();
    for interval in content.split(',') {
        let mut int_split = interval.split('-');
        let start: u64 = int_split.next().unwrap().trim().parse().unwrap();
        let end: u64 = int_split.next().unwrap().trim().parse().unwrap();
        for idx in start..=end {
            if has_repeat(idx) > 0 {
                running_sum = running_sum + idx;
            }
        }
    }
    println!("{}", running_sum);
}
