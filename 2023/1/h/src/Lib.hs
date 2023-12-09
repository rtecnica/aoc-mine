module Lib
  ( parseCalVal,
  )
where

import qualified Data.Char as C
import qualified Data.Text as T

parseCalFw :: T.Text -> Maybe Int
parseCalFw line =
  case T.uncons line of
    Nothing -> Nothing
    Just (c, t) -> case parseAux c of
      Nothing -> parseCalFw t
      Just i -> Just i

parseCalBw :: T.Text -> Maybe Int
parseCalBw line =
  case T.unsnoc line of
    Nothing -> Nothing
    Just (t, c) -> case parseAux c of
      Nothing -> parseCalBw t
      Just i -> Just i

parseAux :: C.Char -> Maybe Int
parseAux c =
  if C.isDigit c
    then Just (C.digitToInt c)
    else Nothing

maybeSum :: Maybe Int -> Maybe Int -> Maybe Int
maybeSum Nothing _ = Nothing
maybeSum _ Nothing = Nothing
maybeSum (Just a) (Just b) =
  Just (a + b)

maybeMul :: Maybe Int -> Maybe Int -> Maybe Int
maybeMul Nothing _ = Nothing
maybeMul _ Nothing = Nothing
maybeMul (Just a) (Just b) =
  Just (a * b)

parseCalVal :: T.Text -> Maybe Int
parseCalVal line =
  maybeSum (maybeMul firstVal (Just 10)) secondVal
  where
    firstVal = parseCalFw line
    secondVal = parseCalBw line
