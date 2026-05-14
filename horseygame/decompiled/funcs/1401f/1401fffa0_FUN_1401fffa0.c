// Address: 0x1401fffa0
// Ghidra name: FUN_1401fffa0
// ============ 0x1401fffa0 FUN_1401fffa0 (size=149) ============


undefined8 FUN_1401fffa0(void)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  undefined8 uVar4;

  uint local_res8 [2];

  

  uVar3 = 0;

  local_res8[0] = 0;

  uVar4 = 0;

  (*DAT_1403fd0d8)(local_res8,0);

  if (local_res8[0] != 0) {

    lVar2 = FUN_1401841a0(local_res8[0],0x208);

    (*DAT_1403fd0d8)(local_res8,lVar2);

    if (local_res8[0] != 0) {

      do {

        iVar1 = strcmp("VK_LAYER_KHRONOS_validation",(char *)((ulonglong)uVar3 * 0x208 + lVar2));

        if (iVar1 == 0) {

          uVar4 = 1;

          break;

        }

        uVar3 = uVar3 + 1;

      } while (uVar3 < local_res8[0]);

    }

    FUN_1401841e0(lVar2);

  }

  return uVar4;

}




