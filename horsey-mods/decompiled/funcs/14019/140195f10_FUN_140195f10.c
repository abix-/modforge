// Address: 0x140195f10
// Ghidra name: FUN_140195f10
// ============ 0x140195f10 FUN_140195f10 (size=478) ============


undefined8 * FUN_140195f10(undefined8 param_1,undefined8 param_2)



{

  ulonglong uVar1;

  char cVar2;

  int iVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  ulonglong *puVar6;

  longlong lVar7;

  undefined4 uVar8;

  undefined8 local_res18;

  undefined4 local_298;

  undefined2 local_294;

  undefined2 local_292;

  undefined2 local_290;

  ulonglong local_288;

  undefined1 local_278 [16];

  undefined2 local_268;

  undefined2 local_266;

  undefined2 local_228 [264];

  

  local_res18 = 0;

  puVar4 = (undefined8 *)FUN_1401841a0(1,0x50);

  if (puVar4 != (undefined8 *)0x0) {

    puVar4[7] = 0;

    uVar5 = FUN_140195ac0(param_1);

    *puVar4 = uVar5;

    *(undefined4 *)((longlong)puVar4 + 0x34) = 0xffffffff;

    local_298 = 0xc;

    cVar2 = (*DAT_1403fcc50)(param_2,&local_298);

    if (cVar2 != '\0') {

      *(undefined2 *)(puVar4 + 1) = local_294;

      *(undefined2 *)((longlong)puVar4 + 10) = local_292;

      *(undefined2 *)(puVar4 + 3) = local_290;

    }

    cVar2 = (*DAT_1403fcc90)(param_2,&local_res18);

    if (cVar2 != '\0') {

      iVar3 = (*DAT_1403fcca0)(local_res18,&local_268);

      if (iVar3 == 0x110000) {

        *(undefined2 *)(puVar4 + 6) = local_266;

        *(undefined2 *)((longlong)puVar4 + 0x32) = local_268;

      }

      (*DAT_1403fcc98)(local_res18);

    }

    puVar6 = (ulonglong *)FUN_140195c10(local_278,param_1);

    local_288 = *puVar6;

    uVar1 = puVar6[1];

    uVar8 = 0x200;

    lVar7 = 0x200;

    iVar3 = (int)(local_288 >> 0x20);

    *(int *)(puVar4 + 8) = iVar3;

    if (iVar3 == 1) {

      lVar7 = 0xfc;

      uVar8 = 0xfc;

    }

    *(undefined2 *)((longlong)local_228 + lVar7) = 0;

    local_228[0] = 0;

    (*DAT_1403fcc58)(param_2,local_228,uVar8);

    uVar5 = FUN_14012fc00(local_228);

    puVar4[2] = uVar5;

    local_228[0] = 0;

    (*DAT_1403fcc60)(param_2,local_228,uVar8);

    uVar5 = FUN_14012fc00(local_228);

    puVar4[4] = uVar5;

    local_228[0] = 0;

    (*DAT_1403fcc68)(param_2,local_228,uVar8);

    uVar5 = FUN_14012fc00(local_228);

    puVar4[5] = uVar5;

    if (*(int *)(puVar4 + 8) == 1) {

      FUN_140196270(puVar4,local_288 & 0xffffffff);

    }

    else if ((*(int *)(puVar4 + 8) == 2) && ((uVar1 & 1) != 0)) {

      FUN_140195e10(puVar4,local_288 & 0xffffffff);

    }

  }

  return puVar4;

}




