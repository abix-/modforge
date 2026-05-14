// Address: 0x14016ae20
// Ghidra name: FUN_14016ae20
// ============ 0x14016ae20 FUN_14016ae20 (size=1537) ============


undefined4 * FUN_14016ae20(ulonglong param_1)



{

  char cVar1;

  char cVar2;

  undefined1 uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  undefined4 uVar10;

  longlong lVar11;

  longlong lVar12;

  ulonglong uVar13;

  undefined4 *puVar14;

  undefined4 *puVar15;

  undefined8 uVar16;

  uint uVar17;

  longlong lVar18;

  ulonglong uVar19;

  bool local_res10;

  bool local_res18;

  undefined8 local_60;

  undefined8 uStack_58;

  

  uVar19 = param_1 & 0xffffffff;

  lVar11 = FUN_140174e70(param_1,"SDL.window.create.title",0);

  uVar4 = FUN_140174c40(uVar19,"SDL.window.create.x",0x1fff0000);

  uVar5 = FUN_140174c40(param_1 & 0xffffffff,"SDL.window.create.y",0x1fff0000);

  iVar6 = FUN_140174c40(uVar19,"SDL.window.create.width",0);

  iVar7 = FUN_140174c40(param_1 & 0xffffffff,"SDL.window.create.height",0);

  lVar12 = FUN_140174d30(param_1 & 0xffffffff,"SDL.window.create.parent",0);

  uVar13 = FUN_14016e0b0(param_1 & 0xffffffff);

  uVar9 = 0;

  local_res10 = false;

  local_res18 = false;

  cVar1 = FUN_1401749e0(uVar19,"SDL.window.create.external_graphics_context",0);

  if (DAT_1403fc410 == 0) {

    cVar2 = thunk_FUN_14017e460(0x20);

    if (cVar2 == '\0') {

      return (undefined4 *)0x0;

    }

    if (DAT_1403fc410 == 0) {

      return (undefined4 *)0x0;

    }

  }

  if (((uVar13 >> 0xc & 1) != 0) &&

     ((lVar12 == 0 || ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(lVar12,1), cVar2 == '\0'))))

     )) {

    FUN_14012e850("Modal windows must specify a parent window");

    return (undefined4 *)0x0;

  }

  if ((uVar13 & 0xc0000) != 0) {

    if ((*(byte *)(DAT_1403fc410 + 0x394) & 2) == 0) {

      FUN_14012e850("That operation is not supported");

      return (undefined4 *)0x0;

    }

    if ((lVar12 == 0) ||

       ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(lVar12,1), cVar2 == '\0')))) {

      FUN_14012e850("Tooltip and popup menu windows must specify a parent window");

      return (undefined4 *)0x0;

    }

    uVar13 = uVar13 & 0xffffffffffffff2e;

  }

  uVar17 = (uint)uVar13 & 0xe1000;

  if ((uVar17 & uVar17 - 1) != 0) {

    FUN_14012e850("Conflicting window type flags specified: 0x%.8x",uVar17);

    return (undefined4 *)0x0;

  }

  if (*(code **)(DAT_1403fc410 + 0x20) != (code *)0x0) {

    (**(code **)(DAT_1403fc410 + 0x20))(DAT_1403fc410);

  }

  if (iVar6 < 1) {

    iVar6 = 1;

  }

  if (iVar7 < 1) {

    iVar7 = 1;

  }

  uVar17 = uVar4 & 0xffff0000;

  if (uVar17 == 0x1fff0000) {

LAB_14016b036:

    uVar9 = uVar4 & 0xffff;

    if (uVar9 == 0) goto LAB_14016b03e;

LAB_14016b05a:

    iVar8 = FUN_14016d5f0(uVar9);

    if (iVar8 < 0) goto LAB_14016b065;

  }

  else {

    if ((uVar5 & 0xffff0000) != 0x1fff0000) {

      if (uVar17 == 0x2fff0000) goto LAB_14016b036;

      if ((uVar5 & 0xffff0000) != 0x2fff0000) goto LAB_14016b111;

    }

    if (uVar17 == 0x2fff0000) goto LAB_14016b036;

LAB_14016b03e:

    if ((((uVar5 & 0xffff0000) == 0x1fff0000) || ((uVar5 & 0xffff0000) == 0x2fff0000)) &&

       (uVar9 = uVar5 & 0xffff, uVar9 != 0)) goto LAB_14016b05a;

LAB_14016b065:

    uVar9 = FUN_14016dba0();

  }

  local_60 = 0;

  uStack_58 = 0;

  FUN_14016d6c0(uVar9,&local_60);

  if (((int)uStack_58 < iVar6) || (uStack_58._4_4_ < iVar7)) {

    FUN_14016d280(uVar9,&local_60);

  }

  local_res10 = (uVar17 + 0xe0010000 & 0xefffffff) == 0;

  if (local_res10) {

    uVar4 = ((int)uStack_58 - iVar6) / 2 + (int)local_60;

  }

  local_res10 = local_res10 && uVar17 == 0x1fff0000;

  uVar17 = uVar5 & 0xffff0000;

  if ((uVar17 == 0x2fff0000) || (uVar17 == 0x1fff0000)) {

    uVar5 = (uStack_58._4_4_ - iVar7) / 2 + local_60._4_4_;

    local_res18 = uVar17 == 0x1fff0000;

  }

LAB_14016b111:

  uVar17 = (uint)uVar13 & 0x30000002;

  if ((uVar17 & uVar17 - 1) != 0) {

    FUN_14012e850("Conflicting window graphics flags specified: 0x%.8x",uVar17);

    return (undefined4 *)0x0;

  }

  lVar18 = DAT_1403fc410;

  if (((uVar13 & 0x30000002) == 0) && (cVar1 == (char)uVar17)) {

    uVar17 = FUN_1400248b0(DAT_1403fc410);

    uVar13 = uVar13 | uVar17;

  }

  if ((uVar13 & 2) != 0) {

    if (*(longlong *)(lVar18 + 0x1b8) == 0) {

      FUN_14016a680("OpenGL");

      return (undefined4 *)0x0;

    }

    cVar2 = FUN_14016c850(0);

    lVar18 = DAT_1403fc410;

    if (cVar2 == '\0') {

      return (undefined4 *)0x0;

    }

  }

  if ((uVar13 >> 0x1c & 1) != 0) {

    if (*(longlong *)(lVar18 + 0x210) == 0) {

      FUN_14016a680("Vulkan");

      return (undefined4 *)0x0;

    }

    cVar2 = FUN_140174130(0);

    lVar18 = DAT_1403fc410;

    if (cVar2 == '\0') {

      return (undefined4 *)0x0;

    }

  }

  if (((uVar13 >> 0x1d & 1) != 0) && (*(longlong *)(lVar18 + 0x228) == 0)) {

    FUN_14016a680("Metal");

    return (undefined4 *)0x0;

  }

  puVar14 = (undefined4 *)FUN_1401841a0(1,0x1c8);

  if (puVar14 == (undefined4 *)0x0) {

    return (undefined4 *)0x0;

  }

  FUN_1401aa9d0(puVar14,1,1);

  uVar10 = FUN_1401aa810();

  *puVar14 = uVar10;

  *(bool *)((longlong)puVar14 + 0x9d) = local_res10;

  *(bool *)((longlong)puVar14 + 0x9e) = local_res18;

  puVar14[6] = uVar4;

  puVar14[0x1b] = uVar4;

  puVar14[0x1f] = uVar4;

  puVar14[7] = uVar5;

  puVar14[0x1c] = uVar5;

  puVar14[0x20] = uVar5;

  puVar14[8] = iVar6;

  puVar14[0x1d] = iVar6;

  puVar14[0x21] = iVar6;

  puVar14[9] = iVar7;

  puVar14[0x1e] = iVar7;

  puVar14[0x22] = iVar7;

  puVar14[0x1a] = uVar9;

  puVar15 = (undefined4 *)FUN_14016de50(puVar14);

  if (puVar15 != (undefined4 *)0x0) {

    FUN_140170e10(puVar14,puVar15 + 0x17,0);

  }

  if (((uVar13 & 1) != 0) || (lVar18 = DAT_1403fc410, cVar2 = FUN_140169e70(), cVar2 != '\0')) {

    if (puVar15 == (undefined4 *)0x0) {

      uVar10 = FUN_14016dba0();

    }

    else {

      uVar10 = *puVar15;

    }

    FUN_14016d280(uVar10,&local_60);

    *(ulonglong *)(puVar14 + 0x14) = *(ulonglong *)(puVar14 + 0x14) | 1;

    lVar18 = DAT_1403fc410;

    uVar13 = uVar13 | 1;

    puVar14[6] = (int)local_60;

    puVar14[7] = local_60._4_4_;

    puVar14[8] = (int)uStack_58;

    puVar14[9] = uStack_58._4_4_;

  }

  puVar14[0x16] = 0x3f800000;

  puVar14[0x3e] = 0x3f800000;

  *(ulonglong *)(puVar14 + 0x12) = uVar13 & 0xf02f2072 | 8;

  *(undefined8 *)(puVar14 + 0x68) = *(undefined8 *)(lVar18 + 0x348);

  *(undefined1 *)((longlong)puVar14 + 0x10f) = 0;

  uVar10 = FUN_14016d540(puVar14);

  puVar14[0x19] = uVar10;

  *(char *)(puVar14 + 0x17) = cVar1;

  uVar3 = FUN_1401749e0(param_1 & 0xffffffff,"SDL.window.create.constrain_popup",1);

  lVar18 = DAT_1403fc410;

  *(undefined1 *)((longlong)puVar14 + 0x10e) = uVar3;

  if (*(longlong *)(lVar18 + 0x188) == 0) {

    *(ulonglong *)(puVar14 + 0x12) = *(ulonglong *)(puVar14 + 0x12) & 0xffffffffffdfffff;

  }

  if (*(longlong *)(lVar18 + 0x348) != 0) {

    *(undefined4 **)(*(longlong *)(lVar18 + 0x348) + 0x198) = puVar14;

  }

  *(undefined4 **)(lVar18 + 0x348) = puVar14;

  FUN_140173720(puVar14,lVar12);

  if ((*(code **)(lVar18 + 0x48) != (code *)0x0) &&

     (cVar1 = (**(code **)(lVar18 + 0x48))(lVar18,puVar14,param_1 & 0xffffffff), cVar1 == '\0')) {

    uVar16 = FUN_14012e730();

    uVar16 = FUN_14012f0d0(uVar16);

    FUN_14016b720(puVar14);

    FUN_14012e850(&DAT_14039bf30,uVar16);

    FUN_1401841e0(uVar16);

    return (undefined4 *)0x0;

  }

  if (lVar11 != 0) {

    FUN_140172440(puVar14,lVar11);

  }

  FUN_14016bc90(puVar14,uVar13);

  FUN_14016a520(puVar14);

  FUN_14012e710();

  return puVar14;

}




