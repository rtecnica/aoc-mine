pub fn get_max_joltage(bank: &str, num_batt: usize) -> u64 {
    let mut joltage = Vec::new();
    for digit in bank.chars().rev() {
        let dee = digit.to_digit(10).unwrap();
        if joltage.len() < num_batt {
            joltage.push(dee);
        } else {
            if joltage[joltage.len() - 1] <= dee {
                let mut removed = false;
                for (i, _) in joltage.iter().enumerate().rev() {
                    if i + 1 < joltage.len() {
                        if joltage[i] > joltage[i + 1] {
                            joltage.remove(i + 1);
                            removed = true;
                            break;
                        }
                    }
                }
                if !removed {
                    joltage.remove(0);
                }
                joltage.push(dee);
            }
        }
    }
    joltage
        .iter()
        .enumerate()
        .map(|(x, y)| *y as u64 * (10 as u64).pow(x as u32))
        .sum()
}
