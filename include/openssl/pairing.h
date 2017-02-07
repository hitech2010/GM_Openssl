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
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */
/*
 * Common routines for all pairing-based crypto schemes
 */

#ifndef HEADER_PAIRING_H
#define HEADER_PAIRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/ec_type1.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * PAIRING will be a opaque object to hold different types of curves and pairings
 * currently only support type1curve
 */
typedef struct pairing_st {
	int curve_type;
	EC_GROUP *group;
} PAIRING;

/* compute tate pairing e(P, Q) over type1curve */
int PAIRING_type1curve_tate(const EC_GROUP *group, BN_GFP2 *r,
	const EC_POINT *P, const EC_POINT *Q, BN_CTX *ctx);

/* compute tate pairing ratio e(P1, Q1)/e(P2, Q2) over type1curve*/
int PAIRING_type1curve_tate_ratio(const EC_GROUP *group, BN_GFP2 *r,
	const EC_POINT *P1, const EC_POINT *Q1, const EC_POINT *P2,
	const EC_POINT *Q2, BN_CTX *bn_ctx);


/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_PAIRING_strings(void);

/* Error codes for the PAIRING functions. */

/* Function codes. */
# define PAIRING_F_BB1CIPHERTEXTBLOCK_HASH_TO_RANGE       121
# define PAIRING_F_BB1IBE_DECRYPT                         100
# define PAIRING_F_BB1IBE_DOUBLE_HASH                     101
# define PAIRING_F_BB1IBE_DO_DECRYPT                      102
# define PAIRING_F_BB1IBE_DO_ENCRYPT                      103
# define PAIRING_F_BB1IBE_ENCRYPT                         104
# define PAIRING_F_BB1IBE_EXTRACT_PRIVATE_KEY             105
# define PAIRING_F_BB1IBE_SETUP                           106
# define PAIRING_F_BFIBE_DECRYPT                          107
# define PAIRING_F_BFIBE_DO_DECRYPT                       108
# define PAIRING_F_BFIBE_DO_ENCRYPT                       109
# define PAIRING_F_BFIBE_ENCRYPT                          110
# define PAIRING_F_BFIBE_EXTRACT_PRIVATE_KEY              111
# define PAIRING_F_BFIBE_SETUP                            112
# define PAIRING_F_BN_GFP2_ADD_BN                         113
# define PAIRING_F_BN_GFP2_DIV_BN                         114
# define PAIRING_F_BN_GFP2_MUL_BN                         115
# define PAIRING_F_BN_GFP2_SET_BN                         116
# define PAIRING_F_BN_GFP2_SUB_BN                         117
# define PAIRING_F_PAIRING_COMPUTE_TATE_TYPE1CURVE        118
# define PAIRING_F_PAIRING_TYPE1CURVE_TATE                123
# define PAIRING_F_TYPE1CURVE_EVAL_LINE_TEXTBOOK          122
# define PAIRING_F_TYPE1CURVE_EVAL_MILLER_TEXTBOOK        119
# define PAIRING_F_TYPE1CURVE_PHI                         120

/* Reason codes. */
# define PAIRING_R_BB1CIPHERTEXT_INVALID_MAC              118
# define PAIRING_R_BB1IBE_HASH_FAILURE                    119
# define PAIRING_R_BFIBE_CIPHERTEXT_FAILURE               100
# define PAIRING_R_BFIBE_FAILURE                          101
# define PAIRING_R_BUFFER_TOO_SMALL                       102
# define PAIRING_R_COMPUTE_OUTLEN_FAILURE                 103
# define PAIRING_R_COMPUTE_TATE_FAILURE                   120
# define PAIRING_R_D2I_FAILURE                            104
# define PAIRING_R_DECRYPT_FAILURE                        105
# define PAIRING_R_DOUBLE_HASH_FAILURE                    121
# define PAIRING_R_ENCRYPT_FAILURE                        106
# define PAIRING_R_GET_TYPE1CURVE_ZETA_FAILURE            107
# define PAIRING_R_HASH_BYTES_FAILURE                     124
# define PAIRING_R_I2D_FAILURE                            108
# define PAIRING_R_INVALID_BFIBE_HASHFUNC                 109
# define PAIRING_R_INVALID_CIPHERTEXT                     125
# define PAIRING_R_INVALID_INPUT                          123
# define PAIRING_R_INVALID_MD                             110
# define PAIRING_R_INVALID_OUTPUT_BUFFER                  122
# define PAIRING_R_INVALID_TYPE1CURVE                     111
# define PAIRING_R_KDF_FAILURE                            126
# define PAIRING_R_NOT_IMPLEMENTED                        112
# define PAIRING_R_NOT_NAMED_CURVE                        113
# define PAIRING_R_PARSE_CURVE_FAILURE                    114
# define PAIRING_R_PARSE_MPK_FAILURE                      115
# define PAIRING_R_PARSE_PAIRING                          116
# define PAIRING_R_RAND_FAILURE                           117

# ifdef  __cplusplus
}
# endif
#endif
