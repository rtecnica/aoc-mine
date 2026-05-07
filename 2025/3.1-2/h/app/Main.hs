{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let lns = map parseLine (T.lines content) 
  let size = 12
  let solutions = map (getMaxJoltage size) lns
  -- mapM_ print solutions
  print (foldl (+) 0 solutions)
