// Address: 0x1401dcdf0
// Ghidra name: FUN_1401dcdf0
// ============ 0x1401dcdf0 FUN_1401dcdf0 (size=289) ============


undefined8 FUN_1401dcdf0(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  int iVar4;

  ulonglong uVar5;

  longlong lVar6;

  undefined8 uVar7;

  float fVar8;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(char *)(lVar1 + 0x60) != '\0') {

    uVar7 = *(undefined8 *)(param_1 + 0x118);

    lVar6 = 0;

    FUN_14016ebe0(uVar7,local_res8,local_res10);

    *(undefined4 *)(lVar1 + 0x20) = local_res8[0];

    *(undefined4 *)(lVar1 + 0x24) = local_res10[0];

    uVar5 = FUN_14016e130(uVar7);

    if ((uVar5 & 1) != 0) {

      lVar6 = FUN_14016e1f0(uVar7);

    }

    if (lVar6 == 0) {

      *(undefined4 *)(lVar1 + 0x48) = 1;

      uVar3 = 0;

      *(undefined4 *)(lVar1 + 0x28) = 0;

    }

    else {

      *(undefined4 *)(lVar1 + 0x48) = 0;

      uVar3 = FUN_1401e0110(*(undefined4 *)(lVar6 + 4));

      *(undefined4 *)(lVar1 + 0x28) = uVar3;

      fVar8 = (float)thunk_FUN_1402e33f0(*(undefined4 *)(lVar6 + 0x14));

      uVar3 = (undefined4)(longlong)fVar8;

    }

    *(undefined4 *)(lVar1 + 0x58) = uVar3;

    cVar2 = FUN_1401de770(param_1);

    if (cVar2 == '\0') {

      return 0;

    }

    *(undefined1 *)(lVar1 + 0x60) = 0;

  }

  if (*(char *)(lVar1 + 0x61) != '\0') {

    iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x148))();

    if (iVar4 == -0x7789f798) {

      cVar2 = FUN_1401de770(param_1);

      if (cVar2 == '\0') {

        return 0;

      }

      iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x148))();

    }

    if (iVar4 < 0) {

      uVar7 = FUN_1401df290("BeginScene()",iVar4);

      return uVar7;

    }

    *(undefined1 *)(lVar1 + 0x61) = 0;

  }

  return 1;

}




