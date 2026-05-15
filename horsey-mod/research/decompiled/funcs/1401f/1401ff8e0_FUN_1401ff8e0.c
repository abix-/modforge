// Address: 0x1401ff8e0
// Ghidra name: FUN_1401ff8e0
// ============ 0x1401ff8e0 FUN_1401ff8e0 (size=651) ============


undefined1

FUN_1401ff8e0(longlong param_1,int *param_2,int *param_3,undefined8 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined1 uVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  

  lVar2 = *(longlong *)(param_2 + 0x4e);

  uVar3 = *(undefined8 *)(param_1 + 0x2e0);

  if (lVar2 == 0) {

    uVar4 = FUN_14012e850("Texture is not currently available");

    return uVar4;

  }

  lVar1 = lVar2 + 0x20;

  cVar5 = FUN_1401ff520(uVar3,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x24),0,*param_3,

                        param_3[1],param_3[2],param_3[3],param_4,param_5,lVar1);

  if (cVar5 != '\0') {

    iVar6 = (param_3[3] + 1) / 2;

    iVar7 = (param_3[2] + 1) / 2;

    if (*param_2 == 0x32315659) {

      cVar5 = FUN_1401ff520(uVar3,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x24),1,

                            *param_3 / 2,param_3[1] / 2,iVar7,iVar6,param_8,param_9,lVar1);

      if ((cVar5 != '\0') &&

         (cVar5 = FUN_1401ff520(uVar3,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x24),2,

                                *param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,

                                (param_3[3] + 1) / 2,param_6,param_7,lVar1), cVar5 != '\0')) {

        return true;

      }

    }

    else {

      cVar5 = FUN_1401ff520(uVar3,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x24),1,

                            *param_3 / 2,param_3[1] / 2,iVar7,iVar6,param_6,param_7,lVar1);

      if (cVar5 != '\0') {

        cVar5 = FUN_1401ff520(uVar3,*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x24),2,

                              *param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,

                              param_8,param_9,lVar1);

        return cVar5 != '\0';

      }

    }

  }

  return false;

}




