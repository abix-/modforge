// Address: 0x140166b70
// Ghidra name: FUN_140166b70
// ============ 0x140166b70 FUN_140166b70 (size=348) ============


ulonglong FUN_140166b70(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4,

                       longlong *param_5,int *param_6)



{

  char cVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong lVar6;

  bool bVar7;

  

  lVar6 = 0;

  if (param_5 != (longlong *)0x0) {

    *param_5 = 0;

  }

  if (param_6 != (int *)0x0) {

    *param_6 = 0;

  }

  if (param_2 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","src_data");

    return uVar4;

  }

  if (param_3 < 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","src_len");

    return uVar4;

  }

  if (param_5 == (longlong *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","dst_data");

    return uVar4;

  }

  if (param_6 == (int *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","dst_len");

    return uVar4;

  }

  bVar7 = false;

  lVar5 = FUN_140167620(param_1,param_4);

  if (((lVar5 != 0) && (cVar1 = FUN_140167ea0(lVar5,param_2,param_3,0,0), cVar1 != '\0')) &&

     (cVar1 = FUN_140167760(lVar5), cVar1 != '\0')) {

    iVar2 = FUN_1401677b0(lVar5);

    lVar6 = 0;

    if ((-1 < iVar2) && (lVar6 = FUN_1401841f0((longlong)iVar2), lVar6 != 0)) {

      iVar3 = FUN_140167ac0(lVar5,lVar6,iVar2);

      bVar7 = iVar3 == iVar2;

      if (bVar7) {

        *param_5 = lVar6;

        *param_6 = iVar2;

        goto LAB_140166ca1;

      }

    }

  }

  FUN_1401841e0(lVar6);

LAB_140166ca1:

  FUN_1401676f0(lVar5);

  return (ulonglong)bVar7;

}




