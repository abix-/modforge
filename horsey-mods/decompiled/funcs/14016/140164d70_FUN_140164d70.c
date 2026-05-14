// Address: 0x140164d70
// Ghidra name: FUN_140164d70
// ============ 0x140164d70 FUN_140164d70 (size=292) ============


ulonglong FUN_140164d70(longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4,

                       undefined8 *param_5,char *param_6)



{

  int iVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  uint uVar5;

  char local_res8 [8];

  undefined8 local_res20;

  undefined8 local_38;

  uint local_30;

  int iStack_2c;

  undefined4 local_28;

  

  uVar2 = FUN_140217dc0(*(undefined8 *)(param_1 + 0x60),param_2,&local_30,&local_38,local_res8);

  if (param_4 != (undefined8 *)0x0) {

    *param_4 = CONCAT44(iStack_2c,local_30);

    *(undefined4 *)(param_4 + 1) = local_28;

  }

  if (param_5 != (undefined8 *)0x0) {

    *param_5 = local_38;

  }

  if (uVar2 != 0xffffffffffffffff) {

    local_res20 = *param_3;

    lVar3 = FUN_1401648f0(param_1);

    uVar5 = (local_30 >> 3 & 0x1f) * iStack_2c;

    uVar4 = uVar2 / uVar5;

    if (lVar3 != 0) {

      if (local_res8[0] == '\0') {

        iVar1 = FUN_140214440(lVar3,uVar2 % (ulonglong)uVar5);

        uVar4 = uVar4 - (longlong)iVar1;

      }

      uVar4 = FUN_1402143d0(uVar4,lVar3,&local_res20);

    }

    if (local_res8[0] != '\0') {

      local_res20 = 0;

    }

    *param_3 = local_res20;

    if (param_6 != (char *)0x0) {

      *param_6 = local_res8[0];

    }

    return uVar4;

  }

  *param_3 = 0;

  if (param_6 != (char *)0x0) {

    *param_6 = '\0';

  }

  return 0x7fffffff;

}




