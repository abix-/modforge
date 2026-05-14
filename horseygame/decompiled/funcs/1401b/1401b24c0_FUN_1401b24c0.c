// Address: 0x1401b24c0
// Ghidra name: FUN_1401b24c0
// ============ 0x1401b24c0 FUN_1401b24c0 (size=1185) ============


undefined8

FUN_1401b24c0(char param_1,longlong param_2,longlong param_3,longlong *param_4,undefined4 *param_5,

             undefined4 *param_6)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  undefined8 *puVar6;

  longlong lVar7;

  undefined8 uVar8;

  undefined8 *puVar9;

  ulonglong uVar10;

  undefined4 local_78 [2];

  undefined8 local_70;

  undefined4 local_68;

  undefined8 local_64;

  undefined4 local_5c;

  undefined8 local_58;

  undefined8 local_50;

  undefined8 local_48;

  undefined8 local_40;

  undefined4 local_38;

  

  puVar2 = param_6;

  puVar1 = param_5;

  puVar9 = *(undefined8 **)(param_2 + 0x110);

  *param_4 = 0;

  if (param_5 != (undefined4 *)0x0) {

    *param_5 = 0;

  }

  if (param_6 != (undefined4 *)0x0) {

    *param_6 = 0;

  }

  puVar6 = (undefined8 *)FUN_1401baca0(param_3);

  if (puVar6 == (undefined8 *)0x0) {

    if (*(char *)((longlong)puVar9 + 0x57c) == '\0') {

      FUN_14012e850(&DAT_14039bf30,"Cannot acquire a swapchain texture from an unclaimed window!");

      return 0;

    }

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Cannot acquire a swapchain texture from an unclaimed window!");

  }

  *(undefined1 *)(param_2 + 0xa99) = 1;

  if ((*(byte *)(param_3 + 0x48) & 8) == 0) {

    if (*(char *)((longlong)puVar6 + 0x1d) != '\0') {

      lVar7 = FUN_14016dcf0();

      (*(code *)puVar9[0x134])(*puVar9,puVar6[5],0);

      cVar3 = (**(code **)(lVar7 + 0x210))(lVar7,*puVar6,*puVar9,0,puVar6 + 5);

      if (cVar3 == '\0') {

        if (*(char *)((longlong)puVar9 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(9,&DAT_14039bf30,"Failed to recreate Vulkan surface!");

        }

        FUN_14012e850(&DAT_14039bf30,"Failed to recreate Vulkan surface!");

        return 0;

      }

    }

    if (*(char *)((longlong)puVar6 + 0x1c) != '\0') {

      iVar4 = FUN_1401bc750(puVar9,puVar6);

      if (iVar4 == 0) {

        return 0;

      }

      if (iVar4 == 2) {

        if (puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0x12] == 0) {

          return 1;

        }

        FUN_1401bf630(puVar9);

        puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0x12] = 0;

        return 1;

      }

      *(undefined1 *)((longlong)puVar6 + 0x1d) = 0;

    }

    if (puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0x12] != 0) {

      if (param_1 == '\0') {

        cVar3 = FUN_1401bf510(puVar9);

        if (cVar3 == '\0') {

          return 1;

        }

      }

      else {

        cVar3 = FUN_1401c0990(puVar9,1,puVar6 + (ulonglong)*(uint *)(puVar6 + 0x15) + 0x12);

        if (cVar3 == '\0') {

          return 0;

        }

      }

      FUN_1401bf630(puVar9,puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0x12]);

      puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0x12] = 0;

    }

    uVar10 = 0;

    iVar4 = (*(code *)puVar9[0x191])

                      (puVar9[0xae],puVar6[6],0xffffffffffffffff,

                       puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0xe],0,&param_5);

    while ((iVar4 != 0 && (iVar4 != 0x3b9acdeb))) {

      iVar4 = FUN_1401bc750(puVar9,puVar6);

      if (iVar4 == 0) {

        return 0;

      }

      if (iVar4 == 2) {

        return 1;

      }

      uVar10 = 0;

      iVar4 = (*(code *)puVar9[0x191])

                        (puVar9[0xae],puVar6[6],0xffffffffffffffff,

                         puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0xe],0,&param_5);

    }

    if (puVar1 != (undefined4 *)0x0) {

      *puVar1 = *(undefined4 *)((longlong)puVar6 + 100);

    }

    if (puVar2 != (undefined4 *)0x0) {

      *puVar2 = *(undefined4 *)(puVar6 + 0xd);

    }

    lVar7 = (ulonglong)(uint)param_5 * 0x50 + puVar6[0xb];

    local_78[0] = 0x2d;

    local_70 = 0;

    local_68 = 0;

    local_64 = 0x100;

    local_5c = 2;

    local_58 = 0xffffffffffffffff;

    local_50 = *(undefined8 *)(*(longlong *)(lVar7 + 0x28) + 0x18);

    local_48 = 1;

    local_40 = 1;

    local_38 = 1;

    (*(code *)puVar9[0x157])

              (*(undefined8 *)(param_2 + 0x118),0x400,0x400,0,uVar10 & 0xffffffff00000000,0,0,0,1,

               local_78);

    if (*(int *)(param_2 + 0x130) == *(int *)(param_2 + 0x134)) {

      uVar5 = *(int *)(param_2 + 0x134) + 1;

      *(uint *)(param_2 + 0x134) = uVar5;

      uVar8 = FUN_140184230(*(undefined8 *)(param_2 + 0x128),(ulonglong)uVar5 << 4);

      *(undefined8 *)(param_2 + 0x128) = uVar8;

    }

    puVar9 = (undefined8 *)

             ((ulonglong)*(uint *)(param_2 + 0x130) * 0x10 + *(longlong *)(param_2 + 0x128));

    *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) + 1;

    *puVar9 = puVar6;

    *(uint *)(puVar9 + 1) = (uint)param_5;

    if (*(int *)(param_2 + 0x140) == *(int *)(param_2 + 0x144)) {

      uVar5 = *(int *)(param_2 + 0x144) + 1;

      *(uint *)(param_2 + 0x144) = uVar5;

      uVar8 = FUN_140184230(*(undefined8 *)(param_2 + 0x138),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_2 + 0x138) = uVar8;

    }

    *(undefined8 *)(*(longlong *)(param_2 + 0x138) + (ulonglong)*(uint *)(param_2 + 0x140) * 8) =

         puVar6[(ulonglong)*(uint *)(puVar6 + 0x15) + 0xe];

    *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + 1;

    if (*(int *)(param_2 + 0x150) == *(int *)(param_2 + 0x154)) {

      uVar5 = *(int *)(param_2 + 0x154) + 1;

      *(uint *)(param_2 + 0x154) = uVar5;

      uVar8 = FUN_140184230(*(undefined8 *)(param_2 + 0x148),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_2 + 0x148) = uVar8;

    }

    *(undefined8 *)(*(longlong *)(param_2 + 0x148) + (ulonglong)*(uint *)(param_2 + 0x150) * 8) =

         *(undefined8 *)(puVar6[0x11] + (ulonglong)(uint)param_5 * 8);

    *(int *)(param_2 + 0x150) = *(int *)(param_2 + 0x150) + 1;

    *param_4 = lVar7;

  }

  return 1;

}




