// Address: 0x14028a1c0
// Ghidra name: FUN_14028a1c0
// ============ 0x14028a1c0 FUN_14028a1c0 (size=170) ============


undefined ** FUN_14028a1c0(longlong param_1,undefined4 *param_2)



{

  bool bVar1;

  bool bVar2;

  int iVar3;

  longlong lVar4;

  uint uVar5;

  uint local_res10 [2];

  

  uVar5 = 0;

  bVar1 = false;

  local_res10[0] = 0;

  if (param_2 != (undefined4 *)0x0) {

    if (*(longlong *)(param_1 + 0x568) != 0) {

      lVar4 = FUN_140241110(*(longlong *)(param_1 + 0x568),local_res10);

      bVar2 = false;

      if (local_res10[0] != 0) {

        do {

          bVar1 = bVar2;

          iVar3 = strcmp("VK_EXT_headless_surface",(char *)((ulonglong)uVar5 * 0x104 + lVar4));

          if (iVar3 == 0) {

            bVar1 = true;

          }

          uVar5 = uVar5 + 1;

          bVar2 = bVar1;

        } while (uVar5 < local_res10[0]);

      }

      FUN_1401841e0(lVar4);

      if (bVar1) {

        *param_2 = 2;

        goto LAB_14028a25b;

      }

    }

    *param_2 = 1;

  }

LAB_14028a25b:

  return &PTR_s_VK_KHR_surface_140380ec8;

}




