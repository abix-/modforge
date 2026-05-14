// Address: 0x14027ebd0
// Ghidra name: FUN_14027ebd0
// ============ 0x14027ebd0 FUN_14027ebd0 (size=1411) ============


undefined8 FUN_14027ebd0(longlong param_1,undefined8 param_2,ushort *param_3,undefined8 param_4)



{

  ushort *puVar1;

  byte bVar2;

  char cVar3;

  char cVar4;

  short sVar5;

  int iVar6;

  undefined8 uVar7;

  byte bVar8;

  uint uVar9;

  undefined8 uVar10;

  ushort uVar11;

  ulonglong uVar12;

  int iVar13;

  undefined8 uVar14;

  

  puVar1 = *(ushort **)(param_1 + 0x70);

  iVar6 = FUN_14027eb10(*(undefined2 *)(param_1 + 0x22));

  uVar9 = 0;

  iVar13 = 0;

  uVar7 = FUN_140149300();

  uVar14 = 0;

  switch(*(undefined2 *)(param_1 + 0x22)) {

  case 0xc24f:

  case 0xc299:

  case 0xc29a:

  case 0xc29b:

    bVar2 = (byte)*param_3;

    bVar8 = (byte)*puVar1;

    break;

  default:

    goto switchD_14027ec4c_caseD_c250;

  case 0xc294:

    bVar2 = (byte)param_3[1];

    bVar8 = (byte)puVar1[1];

    break;

  case 0xc298:

    bVar2 = *(byte *)((longlong)param_3 + 3) >> 4;

    bVar8 = *(byte *)((longlong)puVar1 + 3) >> 4;

    goto LAB_14027ec73;

  }

  bVar2 = bVar2 & 0xf;

  bVar8 = bVar8 & 0xf;

LAB_14027ec73:

  if (bVar2 != bVar8) {

    uVar10 = 0;

    uVar14 = 1;

    switch(bVar2) {

    case 0:

      uVar10 = 1;

      break;

    case 1:

      uVar10 = 3;

      break;

    case 2:

      uVar10 = 2;

      break;

    case 3:

      uVar10 = 6;

      break;

    case 4:

      uVar10 = 4;

      break;

    case 5:

      uVar10 = 0xc;

      break;

    case 6:

      uVar10 = 8;

      break;

    case 7:

      uVar10 = 9;

    }

    FUN_14015ae90(uVar7,param_2,0,uVar10);

  }

switchD_14027ec4c_caseD_c250:

  switch(*(short *)(param_1 + 0x22)) {

  case -0x3db1:

  case -0x3d67:

  case -0x3d66:

  case -0x3d65:

    iVar13 = 4;

    break;

  case -0x3d68:

    iVar13 = 0xe;

  }

  uVar10 = param_4;

  if (*(short *)(param_1 + 0x22) == -0x3d65) {

    iVar6 = iVar6 + -1;

    cVar3 = FUN_14027eaa0(param_3,0x50,param_4);

    cVar4 = FUN_14027eaa0(puVar1,0x50,uVar10);

    if (cVar3 != cVar4) {

      uVar14 = 1;

      FUN_14015ad00(uVar7,param_2,(char)iVar6,cVar3);

      uVar10 = param_4;

    }

  }

  if (0 < iVar6) {

    do {

      uVar12 = (ulonglong)(uVar9 + iVar13);

      cVar3 = FUN_14027eaa0(param_3,uVar12,uVar10);

      cVar4 = FUN_14027eaa0(puVar1,uVar12 & 0xffffffff,param_4);

      if (cVar3 != cVar4) {

        uVar14 = 1;

        FUN_14015ad00(uVar7,param_2,uVar9 & 0xff,cVar3);

      }

      uVar9 = uVar9 + 1;

      uVar10 = param_4;

    } while ((int)uVar9 < iVar6);

  }

  switch(*(undefined2 *)(param_1 + 0x22)) {

  case 0xc24f:

    if (param_3[2] != puVar1[2]) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,0,param_3[2] + 0x8000);

    }

    if ((byte)param_3[3] != (byte)puVar1[3]) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,2,(ushort)(byte)param_3[3] * 0x101 + -0x8000);

    }

    if (*(byte *)((longlong)param_3 + 7) != *(byte *)((longlong)puVar1 + 7)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,3,(ushort)*(byte *)((longlong)param_3 + 7) * 0x101 + -0x8000);

    }

    if ((byte)param_3[4] == (byte)puVar1[4]) goto switchD_14027edee_caseD_c250;

    uVar11 = (ushort)(byte)param_3[4];

    uVar10 = 1;

    break;

  default:

    goto switchD_14027edee_caseD_c250;

  case 0xc294:

    if (*(byte *)((longlong)param_3 + 3) != *(byte *)((longlong)puVar1 + 3)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,0,(ushort)*(byte *)((longlong)param_3 + 3) * 0x101 + -0x8000);

    }

    if ((byte)param_3[2] != (byte)puVar1[2]) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,1,(ushort)(byte)param_3[2] * 0x101 + -0x8000);

    }

    if (*(byte *)((longlong)param_3 + 5) != *(byte *)((longlong)puVar1 + 5)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,2,(ushort)*(byte *)((longlong)param_3 + 5) * 0x101 + -0x8000);

    }

    if ((char)param_3[3] == (char)puVar1[3]) goto switchD_14027edee_caseD_c250;

    uVar11 = (ushort)*(byte *)((longlong)param_3 + 7);

    uVar10 = 3;

    break;

  case 0xc298:

    if ((*param_3 & 0x3fff) != (*puVar1 & 0x3fff)) {

      uVar14 = 1;

      sVar5 = FUN_14027fa80(*param_3 & 0x3fff,puVar1[0x11]);

      FUN_14015aab0(uVar7,param_2,0,(sVar5 + -0x2000) * 4);

    }

    if (*(byte *)((longlong)param_3 + 5) != *(byte *)((longlong)puVar1 + 5)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,1,(ushort)*(byte *)((longlong)param_3 + 5) * 0x101 + -0x8000);

    }

    if ((byte)param_3[3] == (byte)puVar1[3]) goto switchD_14027edee_caseD_c250;

    uVar11 = (ushort)(byte)param_3[3];

    uVar10 = 2;

    break;

  case 0xc299:

  case 0xc29b:

    uVar11 = (ushort)(byte)param_3[2] << 6 | (ushort)(*(byte *)((longlong)param_3 + 3) >> 2);

    if (uVar11 != (ushort)((ushort)(byte)puVar1[2] << 6 |

                          (ushort)(*(byte *)((longlong)puVar1 + 3) >> 2))) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,0,(uVar11 + 0xe000) * 4);

    }

    if (*(byte *)((longlong)param_3 + 5) != *(byte *)((longlong)puVar1 + 5)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,2,(ushort)*(byte *)((longlong)param_3 + 5) * 0x101 + -0x8000);

    }

    if ((byte)param_3[3] != (byte)puVar1[3]) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,3,(ushort)(byte)param_3[3] * 0x101 + -0x8000);

    }

    if (*(byte *)((longlong)param_3 + 7) == *(byte *)((longlong)puVar1 + 7))

    goto switchD_14027edee_caseD_c250;

    uVar11 = (ushort)*(byte *)((longlong)param_3 + 7);

    uVar10 = 1;

    break;

  case 0xc29a:

    if ((param_3[2] & 0x3fff) != (puVar1[2] & 0x3fff)) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,0,((param_3[2] & 0x3fff) + 0xe000) * 4);

    }

    if ((byte)param_3[3] != (byte)puVar1[3]) {

      uVar14 = 1;

      FUN_14015aab0(uVar7,param_2,1,(ushort)(byte)param_3[3] * 0x101 + -0x8000);

    }

    if (*(byte *)((longlong)param_3 + 7) == *(byte *)((longlong)puVar1 + 7))

    goto switchD_14027edee_caseD_c250;

    uVar11 = (ushort)*(byte *)((longlong)param_3 + 7);

    uVar10 = 2;

  }

  uVar14 = 1;

  FUN_14015aab0(uVar7,param_2,uVar10,uVar11 * 0x101 + -0x8000);

switchD_14027edee_caseD_c250:

  FUN_1402f8e20(puVar1,param_3,param_4);

  return uVar14;

}




