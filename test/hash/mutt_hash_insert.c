/**
 * @file
 * Test code for mutt_hash_insert()
 *
 * @authors
 * Copyright (C) 2019 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define TEST_NO_MAIN
#include "acutest.h"
#include "config.h"
#include "mutt/lib.h"

void test_mutt_hash_insert(void)
{
  // struct HashElem *mutt_hash_insert(struct Hash *table, const char *strkey, void *data);

  {
    TEST_CHECK(!mutt_hash_insert(NULL, "apple", "banana"));
  }

  {
    struct Hash *hash = mutt_hash_new(10, MUTT_HASH_NO_FLAGS);
    TEST_CHECK(!mutt_hash_insert(hash, NULL, "banana"));
    mutt_hash_free(&hash);
  }

  {
    struct Hash *hash = mutt_hash_new(10, MUTT_HASH_NO_FLAGS);
    TEST_CHECK(mutt_hash_insert(hash, "apple", NULL) != NULL);
    mutt_hash_free(&hash);
  }
}
