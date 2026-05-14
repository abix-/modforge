// Address: 0x1401ccd30
// Ghidra name: FUN_1401ccd30
// ============ 0x1401ccd30 FUN_1401ccd30 (size=316) ============


ulonglong FUN_1401ccd30(longlong param_1,int param_2,int param_3,uint param_4)



{

  ulonglong uVar1;

  int iVar2;

  undefined4 local_28;

  ulonglong local_24;

  

  local_24 = 0;

  local_28 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2 * 4);

  iVar2 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))

                    (*(longlong **)(param_1 + 0x70),3,&local_28,0xc);

  if (iVar2 < 0) {

    return 0;

  }

  if (param_3 == 0) {

    uVar1 = local_24 & 0x20;

  }

  else if (param_3 == 1) {

    uVar1 = local_24 & 0x20;

  }

  else {

    if (param_3 != 2) {

      if (((param_3 == 3) || (param_3 == 4)) && (-1 < (char)local_24)) {

        return 0;

      }

      goto LAB_1401ccde3;

    }

    uVar1 = local_24 & 0x40;

  }

  if (uVar1 == 0) {

    return 0;

  }

LAB_1401ccde3:

  if (((((((param_4 & 1) == 0) || (((uint)local_24 >> 9 & 1) != 0)) &&

        (((param_4 & 0x18) == 0 || (((uint)local_24 >> 8 & 1) != 0)))) &&

       (((param_4 & 0x20) == 0 || ((char)(local_24 >> 0x20) < '\0')))) &&

      (((param_4 & 0x40) == 0 || ((local_24 & 0x4000000000) != 0)))) &&

     (((param_4 & 2) == 0 || (((uint)local_24 >> 0xe & 1) != 0)))) {

    local_28 = *(undefined4 *)(&DAT_1403e45a0 + (longlong)param_2 * 4);

    local_24 = 0;

    iVar2 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))

                      (*(longlong **)(param_1 + 0x70),3,&local_28,0xc);

    if (-1 < iVar2) {

      if ((param_4 & 4) == 0) {

        return 1;

      }

      return local_24 >> 0x10 & 0xff01;

    }

  }

  return 0;

}




