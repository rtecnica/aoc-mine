{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let ranges = map (parseRange . T.strip) (T.splitOn "," content)
  let repeats = map getRepeats ranges
  let sum_repeats = foldl (+) 0 (map (foldl (+) 0) repeats)
  print sum_repeats
