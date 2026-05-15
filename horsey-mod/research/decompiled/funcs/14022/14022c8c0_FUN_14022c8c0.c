// Address: 0x14022c8c0
// Ghidra name: FUN_14022c8c0
// ============ 0x14022c8c0 FUN_14022c8c0 (size=697) ============


void FUN_14022c8c0(longlong param_1)



{

  undefined1 auVar1 [16];

  longlong lVar2;

  ulonglong uVar3;

  bool bVar4;

  POINT pt;

  POINT pt_00;

  bool bVar5;

  bool bVar6;

  int iVar7;

  int iVar8;

  BOOL BVar9;

  longlong lVar10;

  RECT local_78;

  tagRECT local_68;

  RECT local_58;

  RECT local_48 [2];

  

  lVar2 = *(longlong *)(param_1 + 0x188);

  if (*(char *)(lVar2 + 0x65) != '\0') {

    return;

  }

  if (*(char *)(lVar2 + 0x66) != '\0') {

    return;

  }

  if (*(char *)(lVar2 + 0x67) != '\0') {

    return;

  }

  auVar1 = *(undefined1 (*) [16])(param_1 + 0x150);

  iVar8 = (int)*(undefined8 *)(param_1 + 0x158);

  if ((iVar8 < 1) || ((int)((ulonglong)*(undefined8 *)(param_1 + 0x158) >> 0x20) < 1)) {

    bVar5 = false;

  }

  else {

    bVar5 = true;

  }

  uVar3 = *(ulonglong *)(param_1 + 0x48);

  bVar4 = true;

  if ((((uVar3 >> 0xf & 1) != 0) || ((uVar3 & 0x100) != 0)) || (bVar5)) {

    bVar6 = true;

  }

  else {

    bVar6 = false;

  }

  if (((uVar3 & 0x200) == 0) || (!bVar6)) {

    lVar10 = FUN_14016dcf0();

    BVar9 = GetClipCursor(&local_58);

    if (BVar9 == 0) {

      return;

    }

    if ((lVar10 != 0) &&

       ((local_58.left != *(int *)(lVar10 + 0x338) || (local_58.top != *(int *)(lVar10 + 0x33c)))))

    {

      pt.y = local_58.top;

      pt.x = local_58.left;

      BVar9 = PtInRect((RECT *)(lVar2 + 0x8c),pt);

      if (BVar9 == 0) {

        return;

      }

      pt_00.y = local_58.bottom + -1;

      pt_00.x = local_58.right + -1;

      BVar9 = PtInRect((RECT *)(lVar2 + 0x8c),pt_00);

      if (BVar9 == 0) {

        return;

      }

    }

    ClipCursor((RECT *)0x0);

    local_78.left = 0;

    local_78.top = 0;

    local_78.right = 0;

    local_78.bottom = 0;

  }

  else {

    lVar10 = FUN_1401611a0();

    if ((*(char *)(lVar10 + 0xc1) == '\0') || (*(char *)(lVar10 + 0xc4) == '\0')) {

      bVar4 = false;

    }

    iVar7 = FUN_140229cb0(*(undefined8 *)(lVar2 + 8),&local_68);

    if (iVar7 == 0) {

      return;

    }

    local_78.top = local_68.top;

    local_78.left = local_68.left;

    local_78.bottom = local_68.bottom;

    local_78.right = local_68.right;

    if (bVar4) {

      iVar8 = (local_68.left + local_68.right) / 2;

      iVar7 = (local_68.bottom + local_68.top) / 2;

      local_78.bottom = *(int *)(lVar2 + 0xa8) + iVar7;

      local_78.right = *(int *)(lVar2 + 0xa4) + iVar8;

      local_78.top = *(int *)(lVar2 + 0xa0) + iVar7;

      local_78.left = *(int *)(lVar2 + 0x9c) + iVar8;

    }

    else if (bVar5) {

      local_58.left = auVar1._0_4_ + local_68.left;

      local_58.top = auVar1._4_4_ + local_68.top;

      local_58.right = local_58.left + iVar8;

      local_58.bottom = auVar1._12_4_ + local_58.top;

      BVar9 = IntersectRect(local_48,&local_68,&local_58);

      if (BVar9 == 0) {

        if ((uVar3 & 0x100) == 0) {

          FUN_14022c7f0(param_1);

          return;

        }

      }

      else {

        local_78.left = local_48[0].left;

        local_78.top = local_48[0].top;

        local_78.right = local_48[0].right;

        local_78.bottom = local_48[0].bottom;

      }

    }

    BVar9 = GetClipCursor(&local_68);

    if (BVar9 == 0) {

      return;

    }

    iVar8 = memcmp(&local_78,&local_68,0x10);

    if (iVar8 == 0) {

      return;

    }

    BVar9 = ClipCursor(&local_78);

    if (BVar9 == 0) {

      return;

    }

  }

  *(undefined8 *)(lVar2 + 0x8c) = local_78._0_8_;

  *(undefined8 *)(lVar2 + 0x94) = local_78._8_8_;

  return;

}




