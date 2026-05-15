// Address: 0x1401dfb70
// Ghidra name: FUN_1401dfb70
// ============ 0x1401dfb70 FUN_1401dfb70 (size=426) ============


undefined1 FUN_1401dfb70(longlong param_1,int *param_2,int *param_3,longlong param_4,int param_5)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  undefined1 uVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar4 = FUN_14012e850("Texture is not currently available");

    return uVar4;

  }

  cVar5 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar1,*param_3,param_3[1],param_3[2],

                        param_3[3],param_4,param_5);

  if (cVar5 != '\0') {

    if (*(char *)(lVar1 + 0x48) == '\0') {

      return true;

    }

    param_4 = param_4 + param_3[3] * param_5;

    iVar6 = (param_5 + 1) / 2;

    lVar8 = 0x78;

    if (*param_2 != 0x32315659) {

      lVar8 = 0x50;

    }

    cVar5 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar8 + lVar1,*param_3 / 2,param_3[1] / 2,

                          (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_4,iVar6);

    if (cVar5 != '\0') {

      iVar7 = (param_3[3] + 1) / 2;

      uVar3 = 0x50;

      if (*param_2 != 0x32315659) {

        uVar3 = 0x78;

      }

      cVar5 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar1 + (ulonglong)uVar3,*param_3 / 2,

                            (param_3[1] + 1) / 2,(param_3[2] + 1) / 2,iVar7,param_4 + iVar7 * iVar6,

                            iVar6);

      return cVar5 != '\0';

    }

  }

  return false;

}




