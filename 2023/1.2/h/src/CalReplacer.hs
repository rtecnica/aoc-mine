{-# LANGUAGE OverloadedStrings #-}

module CalReplacer
  ( replaceCal,
  )
where

import qualified Data.Char as C
import qualified Data.List as L
import qualified Data.Text as T

numList :: [(T.Text, Int)]
numList = [("one", 1), ("two", 2), ("three", 3), ("four", 4), ("five", 5), ("six", 6), ("seven", 7), ("eight", 8), ("nine", 9)]

replaceCal :: T.Text -> Maybe T.Text
replaceCal =
  replaceCalRec numList

replaceCalRec :: [(T.Text, Int)] -> T.Text -> Maybe T.Text
replaceCalRec num_list line =
  case T.unsnoc line of
    Nothing -> Nothing
    Just (t, c) -> case replaceCalRec num_list t of
      Nothing -> Just (T.snoc t c)
      Just sline -> Just (replaceCalLine num_list rline)
        where
          rline = T.snoc sline c

replaceCalLine :: [(T.Text, Int)] -> T.Text -> T.Text
replaceCalLine num_list line =
  case L.uncons num_list of
    Nothing -> line
    Just (num_tup, rest) -> T.replace num inttext replaced_line
      where
        inttext = T.cons (C.intToDigit int) (T.tail num)
        num = fst num_tup
        int = snd num_tup
        replaced_line = replaceCalLine rest line
