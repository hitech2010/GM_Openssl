/* ====================================================================
 * Copyright (c) 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES
 * LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */

#include <limits.h>
#include <openssl/evp.h>
#include <openssl/saf.h>
#include <openssl/gmapi.h>
#include "saf_lcl.h"

/* 7.3.31
 * Generate session key returned by `phKeyHandle`
 * Encrypt the symmetric key `hSymmKeyObj` with the input public key
 * `pucPublicKey`, output the encrypted results to `pucSymmKey`, 
 *
 * how can we encrypt data with public key?
 * it this function relies on ther SAF API?
 *
 * The function don't care the input public key. It should be an exported
 * public key. Some extra information should be appened into the output key.
 */
int SAF_GenerateKeyWithEPK(
	void *hSymmKeyObj,
	unsigned char *pucPublicKey,
	unsigned int uiPublicKeyLen,
	unsigned char *pucSymmKey,
	unsigned int uiSymmKeyLen,
	void **phKeyHandle)
{
	int pkey_type;
	EVP_PKEY *pkey = NULL;


	if (!(pkey = d2i_PublicKey(pkey_type, NULL, &p,
		(long)uiPublicKeyLen))) {
	}


}

/* 7.3.32 */
/* all the inforamtion should be kept in encrypted key
 * the encrytped key can be decrypted with the default private key
 */
int SAF_ImportEncedKey(
	void *hSymmKeyObj,
	unsigned char *pucSymmKey,
	unsigned int uiSymmKeyLen,
	void **phKeyHandle)
{
	return 0;
}

/* 7.3.37 */
int SAF_DestroyKeyHandle(
	void *hKeyHandle)
{
	SAF_KeyHandle *hkey = (SAF_KeyHandle *)hKeyHandle;

	if (!hKeyHandle) {
		return SAR_OK;
	}

	OPENSSL_clear_free(hkey->key, hkey->keylen);
	return SAR_OK;
}

