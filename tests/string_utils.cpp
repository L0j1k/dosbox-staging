/*
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *
 *  Copyright (C) 2020-2020  The dosbox-staging team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "string_utils.h"

#include <gtest/gtest.h>

#include <string>

namespace {

TEST(StartsWith, Prefix)
{
	EXPECT_TRUE(starts_with("ab", "abcd"));
	EXPECT_TRUE(starts_with("ab", std::string{"abcd"}));
}

TEST(StartsWith, NotPrefix)
{
	EXPECT_FALSE(starts_with("xy", "abcd"));
	EXPECT_FALSE(starts_with("xy", std::string{"abcd"}));
}

TEST(StartsWith, TooLongPrefix)
{
	EXPECT_FALSE(starts_with("abcd", "ab"));
	EXPECT_FALSE(starts_with("abcd", std::string{"ab"}));
}

TEST(StartsWith, EmptyPrefix)
{
	EXPECT_TRUE(starts_with("", "abcd"));
	EXPECT_TRUE(starts_with("", std::string{"abcd"}));
}

TEST(StartsWith, EmptyString)
{
	EXPECT_FALSE(starts_with("ab", ""));
	EXPECT_FALSE(starts_with("ab", std::string{""}));
}

} // namespace
