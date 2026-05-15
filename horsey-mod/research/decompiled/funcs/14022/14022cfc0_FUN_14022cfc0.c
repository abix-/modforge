// Address: 0x14022cfc0
// Ghidra name: FUN_14022cfc0
// ============ 0x14022cfc0 FUN_14022cfc0 (size=129) ============


undefined8 FUN_14022cfc0(undefined8 param_1,longlong param_2,longlong param_3,uint param_4)



{

  longlong lVar1;

  int *piVar2;

  ulonglong uVar3;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (0 < (int)param_4) {

    piVar2 = (int *)(param_3 + 0xc);

    uVar3 = (ulonglong)param_4;

    do {

      BitBlt(*(HDC *)(lVar1 + 0x18),piVar2[-3],piVar2[-2],piVar2[-1],*piVar2,*(HDC *)(lVar1 + 0x20),

             piVar2[-3],piVar2[-2],0xcc0020);

      piVar2 = piVar2 + 4;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  return 1;

}




