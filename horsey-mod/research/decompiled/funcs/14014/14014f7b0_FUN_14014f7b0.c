// Address: 0x14014f7b0
// Ghidra name: FUN_14014f7b0
// ============ 0x14014f7b0 FUN_14014f7b0 (size=321) ============


ulonglong FUN_14014f7b0(undefined4 *param_1,longlong param_2,undefined8 *param_3)



{

  undefined8 uVar1;

  char cVar2;

  ulonglong uVar3;

  longlong lVar4;

  undefined4 local_res8 [2];

  undefined8 local_res20;

  undefined8 local_28;

  undefined4 local_20;

  undefined4 local_1c;

  

  local_res20 = 0;

  local_res8[0] = 0;

  if (param_1 == (undefined4 *)0x0) {

LAB_14014f8cf:

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,3);

      if (cVar2 == '\0') goto LAB_14014f8cf;

    }

    if (param_3 == (undefined8 *)0x0) {

      uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

      return uVar3;

    }

    local_20 = param_1[1];

    local_1c = param_1[2];

    local_28 = 0;

    if (param_2 != 0) {

      FUN_140185790(param_2,&local_28,&local_28);

    }

    uVar3 = FUN_14014f910(param_1,&local_28,&local_res20,local_res8);

    if ((char)uVar3 != '\0') {

      lVar4 = FUN_140145bc0(local_20,local_1c,*param_1,local_res20,local_res8[0]);

      *(longlong *)(param_1 + 0x4a) = lVar4;

      if (lVar4 == 0) {

        uVar3 = FUN_1401556c0(param_1);

        return uVar3 & 0xffffffffffffff00;

      }

      if (*(longlong *)(param_1 + 0x36) != 0) {

        FUN_1401487f0(lVar4);

      }

      uVar1 = *(undefined8 *)(param_1 + 0x4a);

      *param_3 = uVar1;

      return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




