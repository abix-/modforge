// Address: 0x1401c5ac0
// Ghidra name: FUN_1401c5ac0
// ============ 0x1401c5ac0 FUN_1401c5ac0 (size=807) ============


ulonglong FUN_1401c5ac0(longlong param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  char *pcVar8;

  undefined8 local_res10;

  undefined8 local_res18;

  

  lVar4 = FUN_1401841a0(1,0x9c0);

  if (lVar4 == 0) {

    cVar1 = *(char *)(param_1 + 0x98);

LAB_1401c5da8:

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Failed to create ID3D12CommandList. Out of Memory");

    }

    uVar7 = FUN_14012e850(&DAT_14039bf30,"Failed to create ID3D12CommandList. Out of Memory");

    return uVar7 & 0xffffffffffffff00;

  }

  iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x48))

                    (*(longlong **)(param_1 + 0x70),0,&DAT_140349308,&local_res10);

  if (iVar3 < 0) {

    pcVar8 = "Failed to create ID3D12CommandAllocator";

  }

  else {

    *(undefined8 *)(lVar4 + 0x118) = local_res10;

    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x60))

                      (*(longlong **)(param_1 + 0x70),0,0,local_res10,0,&DAT_140349328,&local_res18)

    ;

    if (-1 < iVar3) {

      *(undefined8 *)(lVar4 + 0x120) = local_res18;

      *(longlong *)(lVar4 + 0x110) = param_1;

      *(undefined8 *)(lVar4 + 0x128) = 0;

      *(undefined4 *)(lVar4 + 0x144) = 1;

      *(undefined4 *)(lVar4 + 0x140) = 0;

      uVar5 = FUN_1401841a0(1,0x10);

      *(undefined8 *)(lVar4 + 0x138) = uVar5;

      *(undefined4 *)(lVar4 + 0x96c) = 4;

      *(undefined4 *)(lVar4 + 0x968) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x960) = uVar5;

      *(undefined4 *)(lVar4 + 0x97c) = 4;

      *(undefined4 *)(lVar4 + 0x978) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x970) = uVar5;

      *(undefined4 *)(lVar4 + 0x98c) = 4;

      *(undefined4 *)(lVar4 + 0x988) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x980) = uVar5;

      *(undefined4 *)(lVar4 + 0x99c) = 4;

      *(undefined4 *)(lVar4 + 0x998) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x990) = uVar5;

      *(undefined4 *)(lVar4 + 0x9ac) = 4;

      *(undefined4 *)(lVar4 + 0x9a8) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x9a0) = uVar5;

      *(undefined4 *)(lVar4 + 0x1fc) = 4;

      *(undefined4 *)(lVar4 + 0x1f8) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x1f0) = uVar5;

      *(undefined4 *)(lVar4 + 0x20c) = 4;

      *(undefined4 *)(lVar4 + 0x208) = 0;

      uVar5 = FUN_1401841a0(4,8);

      *(undefined8 *)(lVar4 + 0x200) = uVar5;

      *(undefined4 *)(lVar4 + 0x9bc) = 4;

      *(undefined4 *)(lVar4 + 0x9b8) = 0;

      lVar6 = FUN_1401841a0(4,8);

      *(longlong *)(lVar4 + 0x9b0) = lVar6;

      if (((((*(longlong *)(lVar4 + 0x138) != 0) && (*(longlong *)(lVar4 + 0x960) != 0)) &&

           (*(longlong *)(lVar4 + 0x970) != 0)) &&

          ((*(longlong *)(lVar4 + 0x980) != 0 && (*(longlong *)(lVar4 + 0x990) != 0)))) &&

         ((*(longlong *)(lVar4 + 0x9a0) != 0 &&

          ((*(longlong *)(lVar4 + 0x200) != 0 && (lVar6 != 0)))))) {

        lVar6 = FUN_140184230(*(undefined8 *)(param_1 + 0x110),

                              (ulonglong)(*(int *)(param_1 + 0x11c) + 1) << 3);

        if (lVar6 != 0) {

          *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;

          *(longlong *)(param_1 + 0x110) = lVar6;

          uVar2 = *(uint *)(param_1 + 0x118);

          *(longlong *)(lVar6 + (ulonglong)uVar2 * 8) = lVar4;

          *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;

          return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);

        }

      }

      FUN_1401c9630(lVar4);

      cVar1 = *(char *)(param_1 + 0x98);

      goto LAB_1401c5da8;

    }

    pcVar8 = "Failed to create ID3D12CommandList";

  }

  FUN_1401cb240(param_1,pcVar8,iVar3);

  uVar7 = FUN_1401c9630(lVar4);

  return uVar7 & 0xffffffffffffff00;

}




