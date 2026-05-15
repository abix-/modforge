// Address: 0x1402855c0
// Ghidra name: FUN_1402855c0
// ============ 0x1402855c0 FUN_1402855c0 (size=130) ============


undefined1 FUN_1402855c0(short param_1,short param_2,short param_3)



{

  char cVar1;

  uint uVar2;

  short local_res20 [4];

  short local_18 [2];

  short local_14 [6];

  

  if (DAT_1403fde20 != '\0') {

    uVar2 = 0;

    do {

      cVar1 = FUN_140285210(uVar2 & 0xff,local_res20,local_18,local_14);

      if ((((cVar1 != '\0') && (param_1 == local_res20[0])) && (param_2 == local_18[0])) &&

         (param_3 == local_14[0])) {

        return 1;

      }

      uVar2 = uVar2 + 1;

    } while ((int)uVar2 < 4);

  }

  return 0;

}




