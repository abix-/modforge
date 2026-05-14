// Address: 0x14020ce30
// Ghidra name: FUN_14020ce30
// ============ 0x14020ce30 FUN_14020ce30 (size=233) ============


undefined8 FUN_14020ce30(longlong param_1,int param_2,short param_3,short param_4)



{

  int *piVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  char *pcVar6;

  int iVar7;

  

  _guard_check_icall();

  if ((param_1 == 0) || (lVar4 = *(longlong *)(param_1 + 0x148), lVar4 == 0)) {

    pcVar6 = "Invalid joystick";

  }

  else {

    if ((-1 < param_2) && (param_2 < (int)(uint)*(ushort *)(lVar4 + 0x38))) {

      lVar2 = (longlong)param_2 * 8;

      piVar1 = (int *)(*(longlong *)(lVar4 + 0xd0) + lVar2);

      *piVar1 = *piVar1 + (int)param_3;

      iVar3 = *(int *)(*(longlong *)(lVar4 + 0xd0) + lVar2);

      iVar7 = -0x8000;

      if ((-0x8001 < iVar3) && (iVar7 = iVar3, 0x7fff < iVar3)) {

        iVar7 = 0x7fff;

      }

      *(int *)(*(longlong *)(lVar4 + 0xd0) + lVar2) = iVar7;

      piVar1 = (int *)(*(longlong *)(lVar4 + 0xd0) + 4 + lVar2);

      *piVar1 = *piVar1 + (int)param_4;

      iVar3 = *(int *)(*(longlong *)(lVar4 + 0xd0) + 4 + lVar2);

      iVar7 = -0x8000;

      if ((-0x8001 < iVar3) && (iVar7 = iVar3, 0x7fff < iVar3)) {

        iVar7 = 0x7fff;

      }

      *(int *)(*(longlong *)(lVar4 + 0xd0) + 4 + lVar2) = iVar7;

      *(uint *)(lVar4 + 0xb0) = *(uint *)(lVar4 + 0xb0) | 2;

      return CONCAT71((uint7)(uint3)((uint)iVar3 >> 8),1);

    }

    pcVar6 = "Invalid ball index";

  }

  uVar5 = FUN_14012e850(pcVar6);

  return uVar5;

}




