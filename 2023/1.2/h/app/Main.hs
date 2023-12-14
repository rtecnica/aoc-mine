{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import CalParser (parseCalVal)
import CalReplacer (replaceCal)
import qualified Data.Maybe as M
import qualified Data.Text as T
import qualified Data.Text.IO as TIO

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let lns = T.splitOn (T.pack "\n") content
  let rplaced_lns = map (M.fromMaybe "" . replaceCal) lns
  -- mapM_ print rplaced_lns
  let nums = map (M.fromMaybe 0 . parseCalVal) rplaced_lns
  -- mapM_ print nums
  let result = sum (map (M.fromMaybe 0 . parseCalVal) rplaced_lns)
  print result
