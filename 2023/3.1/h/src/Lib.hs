{-# LANGUAGE OverloadedStrings #-}

module Lib
  ( parsePartNum,
    parseSymbol,
    isPartNum,
  )
where

import qualified Data.Array as A
import qualified Data.Text as T
import qualified Text.Regex.TDFA
import qualified Text.Regex.TDFA.Text ()

partNumberRegex :: T.Text
partNumberRegex = "[0-9]+"

symbolRegex :: T.Text
symbolRegex = "[^\\.0-9]"

type MatchInstance = (T.Text, (Int, Int))

type MatchMatrix = A.Array Int (A.Array Int MatchInstance)

arrayFromList :: [T.Text] -> A.Array Int T.Text
arrayFromList list = A.listArray (0, lenlen) list
  where
    len = length list
    lenlen = len - 1 :: Int

rawParsePartNum :: T.Text -> MatchMatrix
rawParsePartNum text = Text.Regex.TDFA.getAllTextMatches (text Text.Regex.TDFA.=~ partNumberRegex)

rawParseSymbol :: T.Text -> MatchMatrix
rawParseSymbol text = Text.Regex.TDFA.getAllTextMatches (text Text.Regex.TDFA.=~ symbolRegex)

parsePartNum :: T.Text -> MatchMatrix
parsePartNum text = fmap (fmap (A.! 0)) rawPartNum
  where
    lns = arrayFromList $ T.lines text
    rawPartNum = fmap rawParsePartNum lns

parseSymbol :: T.Text -> MatchMatrix
parseSymbol text = fmap (fmap (A.! 0)) rawSymbol
  where
    lns = arrayFromList $ T.lines text
    rawSymbol = fmap rawParseSymbol lns

isPartNum :: MatchMatrix -> Int -> MatchInstance -> Bool
isPartNum matrix row part_number =
  checkLastRow || checkRow || checkNextRow
  where
    checkLastRow = scanMatchRow lastRow part_number
    checkRow = scanMatchRow nowRow part_number
    checkNextRow = scanMatchRow nextRow part_number
    lastRow = if row > (fst . A.bounds) matrix then A.elems (matrix A.! (row - 1)) else []
    nowRow = A.elems (matrix A.! row)
    nextRow = if row < (snd . A.bounds) matrix then A.elems (matrix A.! (row + 1)) else []

scanMatchRow :: [MatchInstance] -> MatchInstance -> Bool
scanMatchRow [] _ = False
scanMatchRow (h : tl) match =
  is_match || (if past_bound then False else scanMatchRow tl match)
  where
    is_match = (head_start >= match_start) && (head_start <= match_end)
    past_bound = head_start > match_end
    match_start = (fst . snd) match - 1
    match_end = match_start + (snd . snd) match + 1
    head_start = (fst . snd) h
