// Address: 0x14020b5a0
// Ghidra name: FUN_14020b5a0
// ============ 0x14020b5a0 FUN_14020b5a0 (size=452) ============


void FUN_14020b5a0(void)



{

  int iVar1;

  undefined1 local_28 [40];

  

  if (DAT_1403e4ec8 == '\0') {

    if (DAT_1403e4ec9 == '\0') {

      return;

    }

  }

  else {

    iVar1 = (*DAT_1403fddf8)(0,1,local_28);

    DAT_1403fd1e2 = iVar1 == 0;

    iVar1 = (*DAT_1403fddf8)(1,1,local_28);

    DAT_1403fd1fa = iVar1 == 0;

    iVar1 = (*DAT_1403fddf8)(2,1,local_28);

    DAT_1403fd212 = iVar1 == 0;

    iVar1 = (*DAT_1403fddf8)(3,1,local_28);

    DAT_1403fd22a = iVar1 == 0;

    DAT_1403e4ec8 = '\0';

  }

  DAT_1403e4ec9 = 0;

  if (DAT_1403fd1e2 != '\0') {

    iVar1 = (*DAT_1403fdde8)(0,&DAT_1403fd1d0);

    if (iVar1 != 0) {

      DAT_1403fd1e2 = '\0';

    }

    DAT_1403fd1e0 = 0xff;

    if (DAT_1403fde08 != (code *)0x0) {

      (*DAT_1403fde08)(0,0,&DAT_1403fd1e0);

    }

  }

  if (DAT_1403fd1fa != '\0') {

    iVar1 = (*DAT_1403fdde8)(1,&DAT_1403fd1e8);

    if (iVar1 != 0) {

      DAT_1403fd1fa = '\0';

    }

    DAT_1403fd1f8 = 0xff;

    if (DAT_1403fde08 != (code *)0x0) {

      (*DAT_1403fde08)(1,0,&DAT_1403fd1f8);

    }

  }

  if (DAT_1403fd212 != '\0') {

    iVar1 = (*DAT_1403fdde8)(2,&DAT_1403fd200);

    if (iVar1 != 0) {

      DAT_1403fd212 = '\0';

    }

    DAT_1403fd210 = 0xff;

    if (DAT_1403fde08 != (code *)0x0) {

      (*DAT_1403fde08)(2,0,&DAT_1403fd210);

    }

  }

  if (DAT_1403fd22a != '\0') {

    iVar1 = (*DAT_1403fdde8)(3,&DAT_1403fd218);

    if (iVar1 != 0) {

      DAT_1403fd22a = '\0';

    }

    DAT_1403fd228 = 0xff;

    if (DAT_1403fde08 != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014020b75c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fde08)(3,0,&DAT_1403fd228);

      return;

    }

  }

  return;

}




