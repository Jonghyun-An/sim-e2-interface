/* SPDX-License-Identifier: Apache-2.0 */
/* Link and run against each installed library to verify ASN.1 exports. */
#include <stdlib.h>
#include "E2AP-PDU.h"

int main(void) {
    E2AP_PDU_t *pdu = calloc(1, sizeof(*pdu));
    if (pdu == NULL) {
        return 1;
    }
    ASN_STRUCT_FREE(asn_DEF_E2AP_PDU, pdu);
    return 0;
}
