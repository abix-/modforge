// Address: 0x14026a530
// Ghidra name: FUN_14026a530
// ============ 0x14026a530 FUN_14026a530 (size=2200) ============


void FUN_14026a530(undefined8 param_1,longlong *param_2,undefined8 *param_3)



{

  int iVar1;

  longlong lVar2;

  undefined1 uVar3;

  byte bVar4;

  undefined2 uVar5;

  ushort uVar6;

  int iVar7;

  undefined8 uVar8;

  ulonglong uVar9;

  longlong lVar10;

  byte bVar11;

  byte bVar12;

  int iVar13;

  longlong lVar14;

  int iVar15;

  float fVar16;

  undefined1 local_48 [16];

  undefined8 local_38;

  undefined8 uStack_30;

  undefined4 local_28;

  

  uVar8 = FUN_140149300();

  if ((int)param_2[4] == 1) {

    if ((*(longlong *)(*param_2 + 0xa0) == 0) && ((char)param_2[0x1a] == '\0')) {

      FUN_14026b180(uVar8,param_1,param_2,param_3);

    }

    else {

      FUN_140269c30(uVar8,param_1,param_2,param_3);

    }

  }

  else if ((int)param_2[4] == 2) {

    if ((*(longlong *)(*param_2 + 0xa0) == 0) && ((char)param_2[0x1a] == '\0')) {

      FUN_14026b390(uVar8,param_1,param_2,param_3);

    }

    else {

      FUN_140269e10(uVar8,param_1,param_2,param_3);

    }

  }

  else {

    bVar12 = *(byte *)((longlong)param_3 + 2);

    if (bVar12 != *(byte *)(param_2 + 0x1e)) {

      uVar3 = FUN_14026ca40(param_2,0);

      FUN_14015ad00(uVar8,param_1,uVar3);

      uVar3 = FUN_14026ca40(param_2,1);

      FUN_14015ad00(uVar8,param_1,uVar3);

      uVar3 = FUN_14026ca40(param_2,2);

      FUN_14015ad00(uVar8,param_1,uVar3);

      uVar3 = FUN_14026ca40(param_2,3);

      FUN_14015ad00(uVar8,param_1,uVar3);

      FUN_14015ad00(uVar8,param_1,10,bVar12 >> 6 & 1);

    }

    bVar12 = *(byte *)((longlong)param_3 + 3);

    if (bVar12 != *(byte *)((longlong)param_2 + 0xf1)) {

      FUN_14015ad00(uVar8,param_1,4,bVar12 & 1);

      FUN_14015ad00(uVar8,param_1,6,bVar12 >> 1 & 1);

      FUN_14015ad00(uVar8,param_1,8,bVar12 >> 2 & 1);

      FUN_14015ad00(uVar8,param_1,7,bVar12 >> 3 & 1);

      FUN_14015ad00(uVar8,param_1,5,bVar12 >> 4 & 1);

      FUN_14015ad00(uVar8,param_1,0xb,bVar12 >> 5 & 1);

    }

    bVar12 = *(byte *)((longlong)param_3 + 4);

    if (bVar12 != *(byte *)((longlong)param_2 + 0xf2)) {

      bVar4 = (bVar12 & 1) << 2;

      bVar11 = bVar4 | 1;

      if ((bVar12 & 2) == 0) {

        bVar11 = bVar4;

      }

      bVar4 = bVar11 | 2;

      if ((bVar12 & 4) == 0) {

        bVar4 = bVar11;

      }

      bVar11 = bVar4 | 8;

      if ((bVar12 & 8) == 0) {

        bVar11 = bVar4;

      }

      FUN_14015ae90(uVar8,param_1,0,bVar11);

      FUN_14015ad00(uVar8,param_1,9,bVar12 >> 6 & 1);

    }

    FUN_14015aab0(uVar8,param_1,5,(*(char *)((longlong)param_3 + 2) >> 7) + -0x8000);

    FUN_14015aab0(uVar8,param_1,4,(*(char *)((longlong)param_3 + 4) >> 7) + -0x8000);

    uVar5 = FUN_140269080(param_2,0,0,*(ushort *)((longlong)param_3 + 5) & 0xfff);

    FUN_14015aab0(uVar8,param_1,0,uVar5);

    uVar6 = FUN_140269080(param_2,0,1,

                          (ushort)*(byte *)((longlong)param_3 + 7) << 4 |

                          (ushort)(*(byte *)((longlong)param_3 + 6) >> 4));

    FUN_14015aab0(uVar8,param_1,1,~uVar6);

    uVar5 = FUN_140269080(param_2,1,0,*(ushort *)(param_3 + 1) & 0xfff);

    FUN_14015aab0(uVar8,param_1,2,uVar5);

    uVar6 = FUN_140269080(param_2,1,1,

                          (ushort)*(byte *)((longlong)param_3 + 10) << 4 |

                          (ushort)(*(byte *)((longlong)param_3 + 9) >> 4));

    FUN_14015aab0(uVar8,param_1,3,~uVar6);

  }

  bVar12 = *(byte *)((longlong)param_3 + 1) >> 4 & 0xe;

  if ((*(byte *)((longlong)param_3 + 1) & 0x10) == 0) {

    iVar7 = 1;

  }

  else {

    iVar7 = (bVar12 == 8) + 3;

  }

  *(int *)((longlong)param_2 + 0xd4) = iVar7;

  fVar16 = (float)thunk_FUN_1402e1d00((float)bVar12 * DAT_140303358 * DAT_14039ca5c);

  iVar7 = (int)fVar16;

  *(int *)(param_2 + 0x1b) = iVar7;

  if (*(longlong *)(*param_2 + 0xa0) == 0) {

    iVar13 = *(int *)((longlong)param_2 + 0xd4);

    iVar15 = iVar7;

  }

  else {

    if ((int)param_2[4] != 2) goto LAB_14026a98c;

    lVar10 = *(longlong *)(**(longlong **)(*(longlong *)(*param_2 + 0xa0) + 0xb0) + 0x70);

    iVar1 = *(int *)(lVar10 + 0xd4);

    iVar15 = *(int *)(lVar10 + 0xd8);

    iVar13 = *(int *)((longlong)param_2 + 0xd4);

    if (iVar1 <= *(int *)((longlong)param_2 + 0xd4)) {

      iVar13 = iVar1;

    }

    if (iVar7 < iVar15) {

      iVar15 = iVar7;

    }

  }

  FUN_14015af40(param_1,iVar13,iVar15);

LAB_14026a98c:

  if (*(char *)((longlong)param_2 + 0x99) != '\0') {

    local_48 = *(undefined1 (*) [16])((longlong)param_3 + 0xc);

    local_28 = *(undefined4 *)((longlong)param_3 + 0x2c);

    local_38 = *(undefined8 *)((longlong)param_3 + 0x1c);

    uStack_30 = *(undefined8 *)((longlong)param_3 + 0x24);

    if (((local_48._4_2_ == 0) && (local_48._2_2_ == 0)) && (local_48._0_2_ == 0)) {

      if ((*(char *)((longlong)param_2 + 0x9a) != local_48[0]) &&

         (uVar9 = FUN_140149350(), param_2[0x15] + 3000U <= uVar9)) {

        lVar10 = *param_2;

        if (*(char *)(lVar10 + 0x99) != '\0') {

          FUN_140179b60(*(undefined8 *)(lVar10 + 0x78));

        }

        FUN_14026cee0(param_2,1);

        if (*(char *)(lVar10 + 0x99) != '\0') {

          FUN_140179b40(*(undefined8 *)(lVar10 + 0x78));

        }

        param_2[0x15] = uVar9;

      }

    }

    else {

      *(int *)(param_2 + 0x17) = (int)param_2[0x17] + 3;

      *(undefined1 *)((longlong)param_2 + 0x9a) = 1;

      if (999 < *(uint *)(param_2 + 0x17)) {

        lVar10 = FUN_140149300();

        if (lVar10 - param_2[0x16] != 0) {

          param_2[0x18] = (ulonglong)(lVar10 - param_2[0x16]) / (ulonglong)*(uint *)(param_2 + 0x17)

          ;

        }

        *(undefined4 *)(param_2 + 0x17) = 0;

        param_2[0x16] = lVar10;

      }

      lVar2 = param_2[0x18];

      lVar14 = param_2[0x19] + lVar2;

      lVar10 = lVar14 + lVar2;

      lVar2 = lVar10 + lVar2;

      param_2[0x19] = lVar2;

      if ((*(longlong *)(*param_2 + 0xa0) == 0) || ((int)param_2[4] == 2)) {

        FUN_14026cbb0(uVar8,param_1,param_2,2,lVar14,(longlong)&uStack_30 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,1,lVar14,&uStack_30);

        FUN_14026cbb0(uVar8,param_1,param_2,2,lVar10,(longlong)&local_38 + 2);

        FUN_14026cbb0(uVar8,param_1,param_2,1,lVar10,local_48 + 0xc);

        FUN_14026cbb0(uVar8,param_1,param_2,2,lVar2,local_48 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,1,lVar2,local_48);

      }

      if ((*(longlong *)(*param_2 + 0xa0) != 0) && ((int)param_2[4] == 1)) {

        FUN_14026cbb0(uVar8,param_1,param_2,4,lVar14,(longlong)&uStack_30 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,3,lVar14,&uStack_30);

        FUN_14026cbb0(uVar8,param_1,param_2,4,lVar10,(longlong)&local_38 + 2);

        FUN_14026cbb0(uVar8,param_1,param_2,3,lVar10,local_48 + 0xc);

        FUN_14026cbb0(uVar8,param_1,param_2,4,lVar2,local_48 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,3,lVar2,local_48);

      }

      if ((*(longlong *)(*param_2 + 0xa0) != 0) && ((int)param_2[4] == 2)) {

        FUN_14026cbb0(uVar8,param_1,param_2,6,lVar14,(longlong)&uStack_30 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,5,lVar14,&uStack_30);

        FUN_14026cbb0(uVar8,param_1,param_2,6,lVar10,(longlong)&local_38 + 2);

        FUN_14026cbb0(uVar8,param_1,param_2,5,lVar10,local_48 + 0xc);

        FUN_14026cbb0(uVar8,param_1,param_2,6,lVar2,local_48 + 6);

        FUN_14026cbb0(uVar8,param_1,param_2,5,lVar2,local_48);

      }

    }

  }

  uVar8 = param_3[1];

  *(undefined8 *)((longlong)param_2 + 0xee) = *param_3;

  *(undefined8 *)((longlong)param_2 + 0xf6) = uVar8;

  uVar8 = param_3[3];

  *(undefined8 *)((longlong)param_2 + 0xfe) = param_3[2];

  *(undefined8 *)((longlong)param_2 + 0x106) = uVar8;

  uVar8 = param_3[5];

  *(undefined8 *)((longlong)param_2 + 0x10e) = param_3[4];

  *(undefined8 *)((longlong)param_2 + 0x116) = uVar8;

  return;

}




