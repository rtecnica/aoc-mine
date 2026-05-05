{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let lns = T.lines content
  let start = (50, 0)
  let last_state = foldl transitState start (map parseMove lns)
  print last_state
