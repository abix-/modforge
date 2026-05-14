// Address: 0x140028370
// Ghidra name: FUN_140028370
// ============ 0x140028370 FUN_140028370 (size=143) ============


void FUN_140028370(longlong param_1,uint param_2,char param_3)



{

  uint uVar1;

  undefined8 uVar2;

  char *pcVar3;

  undefined1 local_48 [16];

  undefined1 local_38 [48];

  

  uVar1 = 4;

  if (*(longlong *)(param_1 + 0x48) != 0) {

    uVar1 = 0;

  }

  uVar1 = (uVar1 | param_2 | *(uint *)(param_1 + 0x10)) & 0x17;

  *(uint *)(param_1 + 0x10) = uVar1;

  uVar1 = uVar1 & *(uint *)(param_1 + 0x14);

  if (uVar1 != 0) {

    if (param_3 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_1402c8240(0,0);

    }

    if ((uVar1 & 4) == 0) {

      pcVar3 = "ios_base::failbit set";

      if ((uVar1 & 2) == 0) {

        pcVar3 = "ios_base::eofbit set";

      }

    }

    else {

      pcVar3 = "ios_base::badbit set";

    }

    uVar2 = FUN_140024200(local_48,1);

    FUN_140024730(local_38,pcVar3,uVar2);

                    /* WARNING: Subroutine does not return */

    FUN_1402c8240(local_38,&DAT_1403c78a8);

  }

  return;

}




