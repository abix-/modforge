// Address: 0x14013cd50
// Ghidra name: FUN_14013cd50
// ============ 0x14013cd50 FUN_14013cd50 (size=1660) ============


undefined8 FUN_14013cd50(undefined4 *param_1)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  char *pcVar5;

  undefined1 local_res8 [8];

  short local_res10 [4];

  short local_res18 [4];

  undefined2 local_res20 [4];

  undefined4 local_438;

  undefined4 uStack_434;

  undefined4 uStack_430;

  undefined4 uStack_42c;

  undefined1 local_428 [1032];

  

  FUN_14012f1a0(local_428,"none,*,",0x400);

  local_438 = *param_1;

  uStack_434 = param_1[1];

  uStack_430 = param_1[2];

  uStack_42c = param_1[3];

  FUN_1401582b0(&local_438,local_res18,local_res10,local_res20,0);

  cVar2 = FUN_140159780(local_res18[0],local_res10[0]);

  if (cVar2 != '\0') {

    return 0;

  }

  if (local_res18[0] == 0x57e) {

    if (local_res10[0] == 0x337) {

LAB_14013ce39:

      pcVar5 = 

      "a:b0,b:b2,dpdown:b6,dpleft:b4,dpright:b5,dpup:b7,lefttrigger:a4,leftx:a0,lefty:a1~,rightshoulder:b9,righttrigger:a5,rightx:a2,righty:a3~,start:b8,x:b1,y:b3,misc3:b11,misc4:b10,hint:!SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS:=1,"

      ;

    }

    else {

LAB_14013ce4e:

      if (local_res10[0] == 0x2073) {

        pcVar5 = 

        "a:b1,b:b3,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b4,leftshoulder:b6,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b7,righttrigger:a5,rightx:a2,righty:a3,start:b5,x:b0,y:b2,misc1:b8,misc2:b9,misc3:b10,misc4:b11,hint:!SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS:=1,"

        ;

      }

      else if (local_res10[0] == 0x2069) {

        pcVar5 = 

        "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b2,y:b3,misc1:b11,misc2:b12,paddle1:b13,paddle2:b14,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

        ;

      }

      else if (local_res10[0] == 0x2067) {

        cVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_VERTICAL_JOY_CONS",0);

        pcVar5 = 

        "back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,misc1:b11,paddle2:b14,paddle4:b16,"

        ;

        if (cVar2 == '\0') {

          pcVar5 = 

          "a:b1,b:b2,guide:b5,leftshoulder:b9,leftstick:b7,leftx:a0,lefty:a1,rightshoulder:b10,start:b6,x:b3,y:b0,paddle2:b14,paddle4:b16,"

          ;

        }

      }

      else if (local_res10[0] == 0x2066) {

        cVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_VERTICAL_JOY_CONS",0);

        pcVar5 = 

        "a:b0,b:b1,guide:b5,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b2,y:b3,misc2:b12,paddle1:b13,paddle3:b15,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

        ;

        if (cVar2 == '\0') {

          pcVar5 = 

          "a:b1,b:b3,guide:b5,leftshoulder:b9,leftstick:b7,leftx:a0,lefty:a1,rightshoulder:b10,start:b6,x:b0,y:b2,misc2:b12,paddle1:b13,paddle3:b15,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

          ;

        }

      }

      else if (local_res10[0] == 0x2068) {

        pcVar5 = 

        "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b2,y:b3,misc1:b11,misc2:b12,paddle1:b13,paddle2:b14,paddle3:b15,paddle4:b16,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

        ;

      }

      else {

        bVar1 = *(byte *)((longlong)param_1 + 0xf);

        if (((0xd < bVar1) || ((0x3f86U >> (bVar1 & 0x1f) & 1) == 0)) && (1 < (byte)(bVar1 + 0x80)))

        goto LAB_14013d064;

        switch(bVar1) {

        case 7:

        case 9:

        case 10:

          pcVar5 = 

          "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b9,rightshoulder:b10,start:b6,"

          ;

          break;

        case 8:

          pcVar5 = 

          "a:b0,b:b1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b9,rightshoulder:b10,"

          ;

          break;

        case 0xb:

          pcVar5 = 

          "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b9,lefttrigger:a4,rightshoulder:b10,righttrigger:a5,start:b6,x:b2,y:b3,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

          ;

          break;

        case 0xc:

          pcVar5 = 

          "a:b0,b:b1,back:b3,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,lefttrigger:a4,leftx:a0,lefty:a1,misc1:b11,misc2:b4,rightshoulder:b10,righttrigger:b7,start:b6,x:a5,y:b2,"

          ;

          break;

        case 0xd:

          pcVar5 = 

          "a:b0,b:b1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,rightshoulder:b10,righttrigger:a5,start:b6,x:b2,y:b3,misc1:b11,"

          ;

          break;

        default:

          cVar2 = FUN_140142940("SDL_JOYSTICK_HIDAPI_VERTICAL_JOY_CONS",0);

          if (cVar2 == '\0') {

            pcVar5 = 

            "a:b0,b:b1,guide:b5,leftshoulder:b9,leftstick:b7,leftx:a0,lefty:a1,rightshoulder:b10,start:b6,x:b2,y:b3,paddle2:b13,paddle4:b15,"

            ;

            if (bVar1 != 1) {

              pcVar5 = 

              "a:b0,b:b1,guide:b5,leftshoulder:b9,leftstick:b7,leftx:a0,lefty:a1,rightshoulder:b10,start:b6,x:b2,y:b3,paddle1:b12,paddle3:b14,"

              ;

            }

          }

          else {

            pcVar5 = 

            "back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,misc1:b11,paddle2:b13,paddle4:b15,"

            ;

            if (bVar1 != 1) {

              pcVar5 = 

              "a:b0,b:b1,guide:b5,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b2,y:b3,paddle1:b12,paddle3:b14,"

              ;

            }

          }

          break;

        case 0x80:

          pcVar5 = 

          "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,start:b6,x:b2,y:b3,"

          ;

          break;

        case 0x81:

          pcVar5 = 

          "a:b0,b:b1,back:b4,dpdown:b12,dpleft:b13,dpright:b14,dpup:b11,guide:b5,leftshoulder:b9,lefttrigger:a4,leftx:a0,lefty:a1,start:b6,x:b2,y:b3,"

          ;

        }

      }

    }

  }

  else if (local_res18[0] == 0x79) {

    if (((local_res10[0] + 0xe7bdU & 0xfffc) == 0) && (local_res10[0] != 0x1845))

    goto LAB_14013ce39;

LAB_14013d064:

    cVar2 = FUN_140159610();

    if (cVar2 != '\0') {

      FUN_14013d560(local_res18[0],local_res10[0],*(byte *)((longlong)param_1 + 0xf) & 0x1f,

                    local_res20[0],*(byte *)((longlong)param_1 + 0xf) >> 5,local_428,0x400);

      goto LAB_14013d391;

    }

    cVar2 = FUN_140159470(local_res18[0],local_res10[0]);

    pcVar5 = 

    "a:b0,b:b2,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b1,y:b3,hint:!SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS:=1,"

    ;

    if (cVar2 == '\0') {

      pcVar5 = 

      "a:b0,b:b1,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b2,y:b3,"

      ;

    }

    FUN_14012f120(local_428,pcVar5,0x400);

    cVar2 = FUN_140159650(local_res18[0],local_res10[0]);

    if (cVar2 == '\0') {

      cVar2 = FUN_140159690(local_res18[0],local_res10[0]);

      if (cVar2 == '\0') {

        cVar2 = FUN_1401595c0(local_res18[0],local_res10[0]);

        if ((cVar2 == '\0') && (cVar2 = FUN_1401595e0(local_res18[0],local_res10[0]), cVar2 == '\0')

           ) {

          cVar2 = FUN_140159570(local_res18[0],local_res10[0]);

          if (cVar2 == '\0') {

            cVar2 = FUN_1401593b0(local_res18[0],local_res10[0]);

            if (cVar2 != '\0') goto LAB_14013d37a;

            cVar2 = FUN_140159490(local_res18[0],local_res10[0]);

            if (cVar2 == '\0') {

              cVar2 = FUN_140159500(local_res18[0],local_res10[0]);

              if (cVar2 == '\0') {

                cVar2 = FUN_1401594c0(local_res18[0],local_res10[0]);

                if (cVar2 == '\0') {

                  cVar2 = FUN_140159430(local_res18[0],local_res10[0]);

                  if (cVar2 == '\0') {

                    if ((local_res18[0] == 0x2dc8) && (local_res10[0] == 0x6012))

                    goto LAB_14013d04c;

                    local_438 = *param_1;

                    uStack_434 = param_1[1];

                    uStack_430 = param_1[2];

                    uStack_42c = param_1[3];

                    iVar3 = FUN_140157ac0(&local_438,0);

                    if (iVar3 == 3) {

                      cVar2 = FUN_1401597c0(local_res18[0],local_res10[0]);

                      if (cVar2 == '\0') {

                        cVar2 = FUN_140159800(local_res18[0],local_res10[0]);

                        if (cVar2 == '\0') goto LAB_14013d391;

                        goto LAB_14013d37a;

                      }

                      pcVar5 = "paddle1:b11,paddle2:b13,paddle3:b12,paddle4:b14,";

                    }

                    else if (iVar3 == 5) {

                      pcVar5 = "touchpad:b11,";

                    }

                    else {

                      if (iVar3 != 6) {

                        if ((local_res18[0] != 0) || (local_res10[0] != 0)) goto LAB_14013d391;

                        goto LAB_14013d37a;

                      }

                      FUN_14012f120(local_428,"touchpad:b11,misc1:b12,",0x400);

                      cVar2 = FUN_140159400(local_res18[0],local_res10[0]);

                      if (cVar2 == '\0') goto LAB_14013d391;

                      pcVar5 = "paddle1:b16,paddle2:b15,paddle3:b14,paddle4:b13,";

                    }

                  }

                  else {

                    FUN_14012f120(local_428,"paddle1:b11,paddle2:b12,paddle3:b13,paddle4:b14,",0x400

                                 );

                    bVar1 = *(byte *)((longlong)param_1 + 0xf);

                    if (bVar1 < 0x10) {

                      if (bVar1 != 4) goto LAB_14013d391;

                      pcVar5 = "misc2:b15,misc3:b16,";

                    }

                    else {

                      FUN_14012f120(local_428,"misc2:b15,misc3:b16,",0x400);

                      if (bVar1 != 0x15) goto LAB_14013d391;

                      pcVar5 = "misc4:b17,misc5:b18,misc6:b19";

                    }

                  }

                }

                else {

                  pcVar5 = 

                  "paddle1:b13,paddle2:b12,paddle3:b15,paddle4:b14,misc2:b11,misc3:b16,misc4:b17";

                }

              }

              else {

                FUN_14012f120(local_428,"misc1:b11,",0x400);

                if (local_res10[0] != 0x7210) goto LAB_14013d391;

                pcVar5 = "touchpad:b12,misc2:b13,misc3:b14,";

              }

            }

            else {

              pcVar5 = "misc1:b11,misc2:b12,";

            }

          }

          else {

            pcVar5 = "misc1:b11,paddle1:b12,paddle2:b13,paddle3:b14,paddle4:b15,";

          }

        }

        else {

LAB_14013d37a:

          pcVar5 = "misc1:b11,";

        }

      }

      else {

        pcVar5 = "misc1:b11,paddle1:b12,paddle2:b13,paddle3:b14,paddle4:b15";

      }

    }

    else {

      pcVar5 = "paddle1:b11,paddle2:b12,";

    }

  }

  else {

    if (local_res18[0] == 0x57e) goto LAB_14013ce4e;

    if ((local_res18[0] != 0x2dc8) ||

       (((9 < (ushort)(local_res10[0] + 0xa000U) ||

         ((0x24bU >> ((ushort)(local_res10[0] + 0xa000U) & 0x1f) & 1) == 0)) &&

        (1 < (ushort)(local_res10[0] + 0x9f00U))))) goto LAB_14013d064;

    FUN_14012f120(local_428,

                  "a:b1,b:b0,back:b4,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b5,leftshoulder:b9,leftstick:b7,lefttrigger:a4,leftx:a0,lefty:a1,rightshoulder:b10,rightstick:b8,righttrigger:a5,rightx:a2,righty:a3,start:b6,x:b3,y:b2,hint:!SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1,"

                  ,0x400);

    if ((local_res10[0] == 0x6003) || (local_res10[0] == 0x6006)) {

      pcVar5 = "paddle1:b14,paddle2:b13,";

      goto LAB_14013d381;

    }

    if (local_res10[0] != 0x6009) goto LAB_14013d391;

LAB_14013d04c:

    pcVar5 = "paddle1:b12,paddle2:b11,paddle3:b14,paddle4:b13,";

  }

LAB_14013d381:

  FUN_14012f120(local_428,pcVar5,0x400);

LAB_14013d391:

  local_438 = *param_1;

  uStack_434 = param_1[1];

  uStack_430 = param_1[2];

  uStack_42c = param_1[3];

  uVar4 = FUN_14013fc10(&local_438,local_428,local_res8,0);

  return uVar4;

}




