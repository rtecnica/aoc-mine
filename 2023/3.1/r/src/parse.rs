use regex::Regex;

fn parse_regexpr(regexpr: Regex, line: &str) -> Vec<(&str, usize, usize)> {
    regexpr
        .find_iter(line)
        .map(|c| (c.as_str(), c.range().start, c.range().end))
        .collect()
}

fn parse_part_number(line: &str) -> Vec<(&str, usize, usize)> {
    let part_number_regex = Regex::new(r"[0-9]+").unwrap();
    parse_regexpr(part_number_regex, line)
}

fn parse_symbol(line: &str) -> Vec<(&str, usize, usize)> {
    let symbol_regex = Regex::new(r"[^\.0-9]").unwrap();
    parse_regexpr(symbol_regex, line)
}

pub fn parse_part_table(lines: Vec<(usize, &str)>) -> Vec<(usize, Vec<(&str, usize, usize)>)> {
    lines
        .iter()
        .map(|l| (l.0, parse_part_number(l.1)))
        .collect()
}

pub fn parse_symbol_table(lines: Vec<(usize, &str)>) -> Vec<(usize, Vec<(&str, usize, usize)>)> {
    lines.iter().map(|l| (l.0, parse_symbol(l.1))).collect()
}

fn scan_row(mmatch: &(&str, usize, usize), table: &(usize, Vec<(&str, usize, usize)>)) -> bool {
    for item in &table.1 {
        match (
            (mmatch.2) >= item.1,
            ((mmatch.1 as i64) - 1) <= (item.1 as i64),
        ) {
            (true, true) => return true,
            (false, _) => return false,
            (true, false) => continue,
        };
    }
    return false;
}

pub fn num_is_part_num(
    linenum: usize,
    nummatch: &(&str, usize, usize),
    table: &Vec<(usize, Vec<(&str, usize, usize)>)>,
) -> bool {
    let mut result = scan_row(nummatch, &table[linenum]);
    let bounds = (0, table.len() - 1);
    if linenum > bounds.0 && !result {
        result = result || scan_row(nummatch, &table[linenum - 1]);
    };
    if linenum < bounds.1 && !result {
        result = result || scan_row(nummatch, &table[linenum + 1]);
    }
    result
}

pub fn print_table(table: &Vec<(usize, Vec<(&str, usize, usize)>)>) {
    for row in table {
        print!("{}: ", row.0);
        for item in &row.1 {
            print!("{}({},{}) ", item.0, item.1, item.2);
        }
        println!("");
    }
}
