// Address: 0x140187450
// Ghidra name: FUN_140187450
// ============ 0x140187450 FUN_140187450 (size=2112) ============


longlong FUN_140187450(longlong param_1,char param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  char cVar3;

  int iVar4;

  undefined4 uVar5;

  uint uVar6;

  longlong lVar7;

  char *_Str1;

  longlong lVar8;

  uint *puVar9;

  ulonglong uVar10;

  uint uVar11;

  undefined4 *puVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  longlong lVar15;

  ulonglong uVar16;

  undefined2 local_res8;

  char local_res10;

  char local_res18;

  ushort local_res20 [4];

  ushort local_88 [2];

  uint local_84;

  undefined4 local_80;

  undefined4 local_7c;

  undefined4 local_78;

  uint local_74;

  uint local_70;

  uint local_6c;

  int local_68;

  undefined4 local_64;

  uint local_60 [2];

  longlong local_58;

  

  lVar15 = 0;

  local_80 = 0;

  local_7c = 0;

  local_78 = 0;

  local_64 = 0;

  local_res18 = '\0';

  local_6c = 0;

  local_74 = 0;

  local_88[0] = 0;

  local_68 = 0;

  local_70 = 0;

  local_res10 = param_2;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    lVar15 = 0;

  }

  else {

    lVar7 = FUN_14012cba0();

    lVar8 = 0;

    local_58 = lVar7;

    if (-1 < lVar7) {

      FUN_14012e710();

      cVar3 = FUN_1401873d0(param_1);

      lVar8 = lVar15;

      if (cVar3 == '\0') {

        FUN_14012e850("File is not a Windows BMP file");

      }

      else {

        cVar3 = FUN_14012c8c0(param_1,0);

        if (((((cVar3 != '\0') && (cVar3 = FUN_14012c940(param_1,0), cVar3 != '\0')) &&

             (cVar3 = FUN_14012c8c0(param_1,0), cVar3 != '\0')) &&

            ((cVar3 = FUN_14012c8c0(param_1,0), cVar3 != '\0' &&

             (cVar3 = FUN_14012c940(param_1,local_60), cVar3 != '\0')))) &&

           (cVar3 = FUN_14012c940(param_1,&local_84), cVar3 != '\0')) {

          if (local_84 == 0xc) {

            cVar3 = FUN_14012c8c0(param_1,&local_res8);

            if (((cVar3 != '\0') &&

                ((cVar3 = FUN_14012c8c0(param_1,local_res20), cVar3 != '\0' &&

                 (cVar3 = FUN_14012c8c0(param_1,0), cVar3 != '\0')))) &&

               (cVar3 = FUN_14012c8c0(param_1,local_88), cVar3 != '\0')) {

              local_6c = (uint)local_res8;

              local_74 = (uint)local_res20[0];

LAB_140187783:

              if (((int)local_6c < 1) || (local_74 == 0)) {

                FUN_14012e850("BMP file with bad dimensions (%dx%d)");

              }

              else {

                if ((int)local_74 < 0) {

                  local_74 = -local_74;

                  local_res8 = CONCAT11(local_res8._1_1_,1);

                }

                else {

                  local_res8 = (ushort)local_res8._1_1_ << 8;

                }

                _Str1 = (char *)FUN_14012e730();

                iVar4 = strcmp(_Str1,"");

                if (iVar4 == 0) {

                  if ((((local_88[0] == 0) || (local_88[0] == 3)) || (local_88[0] == 5)) ||

                     ((local_88[0] == 6 || (local_88[0] == 7)))) {

                    FUN_14012e850("%u bpp BMP images are not supported",local_88[0]);

                  }

                  else {

                    if (local_68 == 0) {

                      if ((local_88[0] == 0xf) || (local_88[0] == 0x10)) {

                        local_80 = 0x7c00;

                        local_7c = 0x3e0;

                        local_78 = 0x1f;

                      }

                      else {

                        if (local_88[0] != 0x18) {

                          if (local_88[0] != 0x20) goto LAB_140187865;

                          local_res18 = '\x01';

                          local_64 = 0xff000000;

                        }

                        local_80 = 0xff0000;

                        local_7c = 0xff00;

                        local_78 = 0xff;

                      }

                    }

LAB_140187865:

                    uVar5 = FUN_14017aa70(local_88[0],local_80,local_7c,local_78,local_64);

                    lVar8 = FUN_140145e60(local_6c,local_74,uVar5);

                    if (lVar8 != 0) {

                      uVar11 = *(uint *)(lVar8 + 4);

                      if (((uVar11 == 0) || ((uVar11 & 0xf0000000) == 0x10000000)) &&

                         ((uVar11 = uVar11 & 0xf000000, uVar11 == 0x1000000 ||

                          (((uVar11 == 0xc000000 || (uVar11 == 0x2000000)) || (uVar11 == 0x3000000))

                          )))) {

                        puVar9 = (uint *)FUN_140145d20(lVar8);

                        if (puVar9 != (uint *)0x0) {

                          lVar15 = FUN_14012cb40(param_1,(ulonglong)local_84 + 0xe + lVar7,0);

                          if (lVar15 < 0) {

                            FUN_14012e850("Error seeking in datastream");

                          }

                          else if (local_88[0] < 0x20) {

                            if (local_70 == 0) {

                              local_70 = 1 << ((byte)local_88[0] & 0x1f);

                            }

                            if ((local_70 <= *puVar9) ||

                               (local_70 = 1 << ((byte)local_88[0] & 0x1f), local_70 <= *puVar9)) {

                              iVar4 = 0;

                              *puVar9 = local_70;

                              if (local_84 == 0xc) {

                                if (0 < (int)local_70) {

                                  lVar15 = 0;

                                  do {

                                    lVar1 = (longlong)iVar4 * 4;

                                    cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) + 2 +

                                                                  lVar1);

                                    if (((cVar3 == '\0') ||

                                        (cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) + 1

                                                                       + lVar1), cVar3 == '\0')) ||

                                       (cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) +

                                                                      lVar1), cVar3 == '\0'))

                                    goto LAB_140187c30;

                                    iVar4 = iVar4 + 1;

                                    *(undefined1 *)(*(longlong *)(puVar9 + 2) + 3 + lVar15) = 0xff;

                                    lVar15 = lVar15 + 4;

                                  } while (iVar4 < (int)*puVar9);

                                }

                              }

                              else if (0 < (int)local_70) {

                                lVar15 = 0;

                                do {

                                  lVar1 = (longlong)iVar4 * 4;

                                  cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) + 2 +

                                                                lVar1);

                                  if (((cVar3 == '\0') ||

                                      (cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) + 1 +

                                                                     lVar1), cVar3 == '\0')) ||

                                     ((cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) +

                                                                     lVar1), cVar3 == '\0' ||

                                      (cVar3 = FUN_14012c840(param_1,*(longlong *)(puVar9 + 2) + 3 +

                                                                     lVar1), cVar3 == '\0'))))

                                  goto LAB_140187c30;

                                  iVar4 = iVar4 + 1;

                                  *(undefined1 *)(*(longlong *)(puVar9 + 2) + 3 + lVar15) = 0xff;

                                  lVar15 = lVar15 + 4;

                                } while (iVar4 < (int)*puVar9);

                              }

                              goto LAB_140187a8c;

                            }

                            FUN_14012e850("Unsupported or incorrect biClrUsed field");

                          }

                          else {

                            FUN_14012e850("Unsupported or incorrect biBitCount field");

                          }

                        }

                      }

                      else {

LAB_140187a8c:

                        lVar15 = FUN_14012cb40(param_1,(ulonglong)local_60[0] + lVar7,0);

                        if (lVar15 < 0) {

                          FUN_14012e850("Error seeking in datastream");

                        }

                        else {

                          if (1 < local_68 - 1U) {

                            uVar11 = *(uint *)(lVar8 + 0x10);

                            lVar15 = (longlong)(int)uVar11;

                            uVar2 = *(ulonglong *)(lVar8 + 0x18);

                            uVar16 = (longlong)(int)(uVar11 * *(int *)(lVar8 + 0xc)) + uVar2;

                            uVar6 = uVar11 & 0x80000003;

                            if ((int)uVar6 < 0) {

                              uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;

                            }

                            iVar4 = 4 - uVar6;

                            if (uVar6 == 0) {

                              iVar4 = 0;

                            }

                            uVar14 = uVar2;

                            if ((char)local_res8 != '\0') goto joined_r0x000140187b13;

                            for (uVar14 = uVar16 - lVar15; uVar11 = (uint)lVar15, uVar2 <= uVar14;

                                uVar14 = uVar14 + lVar7) {

joined_r0x000140187b13:

                              if (uVar16 <= uVar14) break;

                              lVar15 = FUN_14012c730(param_1,uVar14,(longlong)(int)uVar11);

                              lVar7 = local_58;

                              if (lVar15 != (int)uVar11) goto LAB_140187c30;

                              uVar13 = 0;

                              if (((local_88[0] == 8) && (*(longlong *)(lVar8 + 0x48) != 0)) &&

                                 ((local_70 < 0x100 &&

                                  (uVar10 = uVar13, 0 < (longlong)*(int *)(lVar8 + 8))))) {

                                do {

                                  if (local_70 <= *(byte *)(uVar10 + uVar14)) {

                                    FUN_14012e850(

                                                 "A BMP image contains a pixel with a color out of the palette"

                                                 );

                                    lVar7 = local_58;

                                    goto LAB_140187c30;

                                  }

                                  uVar10 = uVar10 + 1;

                                } while ((longlong)uVar10 < (longlong)*(int *)(lVar8 + 8));

                              }

                              if (0 < iVar4) {

                                do {

                                  cVar3 = FUN_14012c840(param_1,local_res20);

                                  lVar7 = local_58;

                                  if (cVar3 == '\0') goto LAB_140187c30;

                                  uVar11 = (int)uVar13 + 1;

                                  uVar13 = (ulonglong)uVar11;

                                } while ((int)uVar11 < iVar4);

                              }

                              lVar15 = (longlong)*(int *)(lVar8 + 0x10);

                              lVar7 = lVar15;

                              if ((char)local_res8 == '\0') {

                                lVar7 = -lVar15;

                              }

                            }

                            if (local_res18 != '\0') {

                              FUN_140187180(lVar8);

                            }

                            goto LAB_140187c49;

                          }

                          cVar3 = FUN_140188360(lVar8,param_1,local_68 == 1);

                          if (cVar3 != '\0') goto LAB_140187c49;

                          FUN_14012e850("Error reading from datastream");

                        }

                      }

                    }

                  }

                }

              }

            }

          }

          else {

            if (local_84 < 0x28) goto LAB_140187783;

            cVar3 = thunk_FUN_14012c940(param_1,&local_6c);

            if ((((cVar3 == '\0') || (cVar3 = thunk_FUN_14012c940(param_1,&local_74), cVar3 == '\0')

                 ) || ((cVar3 = FUN_14012c8c0(param_1,0), cVar3 == '\0' ||

                       (((cVar3 = FUN_14012c8c0(param_1,local_88), cVar3 == '\0' ||

                         (cVar3 = FUN_14012c940(param_1,&local_68), cVar3 == '\0')) ||

                        (cVar3 = FUN_14012c940(param_1,0), cVar3 == '\0')))))) ||

               (((cVar3 = FUN_14012c940(param_1,0), cVar3 == '\0' ||

                 (cVar3 = FUN_14012c940(param_1,0), cVar3 == '\0')) ||

                ((cVar3 = FUN_14012c940(param_1,&local_70), cVar3 == '\0' ||

                 (cVar3 = FUN_14012c940(param_1,0), cVar3 == '\0')))))) goto LAB_140187c30;

            if (local_84 == 0x40) {

LAB_140187745:

              iVar4 = FUN_14012cba0(param_1);

              uVar11 = iVar4 + (-0xe - (int)lVar7);

              if ((local_84 <= uVar11) ||

                 (lVar15 = FUN_14012cb40(param_1,local_84 - uVar11,1), -1 < lVar15))

              goto LAB_140187783;

            }

            else if (local_68 == 3) {

              cVar3 = FUN_14012c940(param_1,&local_80);

              if (((cVar3 != '\0') && (cVar3 = FUN_14012c940(param_1,&local_7c), cVar3 != '\0')) &&

                 (cVar3 = FUN_14012c940(param_1,&local_78), cVar3 != '\0')) {

                if (0x37 < local_84) {

                  puVar12 = &local_64;

LAB_140187735:

                  cVar3 = FUN_14012c940(param_1,puVar12);

                  if (cVar3 == '\0') goto LAB_140187c30;

                }

                goto LAB_140187745;

              }

            }

            else if ((local_84 < 0x34) ||

                    (((cVar3 = FUN_14012c940(param_1,0), cVar3 != '\0' &&

                      (cVar3 = FUN_14012c940(param_1,0), cVar3 != '\0')) &&

                     (cVar3 = FUN_14012c940(param_1,0), cVar3 != '\0')))) {

              if (0x37 < local_84) {

                puVar12 = (undefined4 *)0x0;

                goto LAB_140187735;

              }

              goto LAB_140187745;

            }

          }

        }

      }

    }

LAB_140187c30:

    FUN_14012cb40(param_1,lVar7,0);

    lVar15 = lVar8;

  }

  lVar8 = 0;

  FUN_140146010(lVar15);

LAB_140187c49:

  if ((local_res10 != '\0') && (param_1 != 0)) {

    FUN_14012bd50(param_1);

  }

  return lVar8;

}




