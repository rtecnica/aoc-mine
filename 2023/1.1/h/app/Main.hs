module Main (main) where

import qualified Data.Maybe as M
import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib (parseCalVal)

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let lns = T.splitOn (T.pack "\n") content
  let result = sum (map (M.fromMaybe 0 . parseCalVal) lns)
  print result
