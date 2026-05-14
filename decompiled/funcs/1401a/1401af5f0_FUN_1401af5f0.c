// Address: 0x1401af5f0
// Ghidra name: FUN_1401af5f0
// ============ 0x1401af5f0 FUN_1401af5f0 (size=566) ============


undefined8 FUN_1401af5f0(undefined8 *param_1,undefined8 param_2)



{

  uint uVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  undefined8 *puVar6;

  undefined8 uVar7;

  undefined4 local_res8 [2];

  undefined4 local_res18 [4];

  

  lVar5 = FUN_1401baca0(param_2);

  if (lVar5 != 0) {

    if (*(undefined8 **)(lVar5 + 8) == param_1) {

      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;

      return 1;

    }

    if (*(char *)((longlong)param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Window already claimed");

    }

    FUN_14012e850(&DAT_14039bf30,"Window already claimed");

    return 0;

  }

  puVar6 = (undefined8 *)FUN_1401841a0(1,0xb0);

  if (puVar6 == (undefined8 *)0x0) {

    return 0;

  }

  *puVar6 = param_2;

  puVar6[1] = param_1;

  *(undefined4 *)(puVar6 + 2) = 1;

  *(undefined8 *)((longlong)puVar6 + 0x14) = 0;

  FUN_140172f40(param_2);

  FUN_14016ebe0(param_2,local_res8,local_res18);

  *(undefined4 *)(puVar6 + 4) = local_res8[0];

  *(undefined4 *)((longlong)puVar6 + 0x24) = local_res18[0];

  lVar5 = FUN_14016dcf0();

  if (lVar5 == 0) {

    FUN_1401841e0(puVar6);

    uVar7 = FUN_14012e850("No video device found");

    return uVar7;

  }

  if (*(code **)(lVar5 + 0x210) == (code *)0x0) {

    FUN_1401841e0(puVar6);

    uVar7 = FUN_14012e850("Video device does not implement Vulkan_CreateSurface");

    return uVar7;

  }

  cVar2 = (**(code **)(lVar5 + 0x210))(lVar5,*puVar6,*param_1,0,puVar6 + 5);

  if (cVar2 != '\0') {

    iVar3 = FUN_1401b7430(param_1,puVar6);

    if (iVar3 == 1) {

      uVar4 = FUN_14016ea50(param_2);

      FUN_140175480(uVar4,"SDL.internal.gpu.vulkan.data",puVar6);

      FUN_140179b40(param_1[0x122]);

      if (*(uint *)((longlong)param_1 + 0x7bc) <= *(uint *)(param_1 + 0xf7)) {

        uVar1 = *(uint *)((longlong)param_1 + 0x7bc) * 2;

        *(uint *)((longlong)param_1 + 0x7bc) = uVar1;

        uVar7 = FUN_140184230(param_1[0xf6],(ulonglong)uVar1 << 3);

        param_1[0xf6] = uVar7;

      }

      *(undefined8 **)(param_1[0xf6] + (ulonglong)*(uint *)(param_1 + 0xf7) * 8) = puVar6;

      *(int *)(param_1 + 0xf7) = *(int *)(param_1 + 0xf7) + 1;

      FUN_140179b60(param_1[0x122]);

      FUN_1401cd9b0(1,FUN_1401bbb00,param_2);

    }

    else {

      if (iVar3 != 2) {

        (*(code *)param_1[0x134])(*param_1,puVar6[5],0);

        goto LAB_1401af7bc;

      }

      *(undefined1 *)((longlong)puVar6 + 0x1c) = 1;

    }

    return 1;

  }

LAB_1401af7bc:

  FUN_1401841e0(puVar6);

  return 0;

}




