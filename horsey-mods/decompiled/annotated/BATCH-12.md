# Batch annotation 12 — 200 functions

Terse mode. Only specific game-logic strings get unique names; the rest are
classified by call-graph context.

## 646-845 (200 functions)

| # | Addr | Size | Name | Note |
|---|---|---|---|---|
| 646 | `0x1400a6cb0` | 244 | helper | unnamed |
| 647 | `0x140075a80` | 243 | save_helper | save |
| 648 | `0x1402e01d4` | 241 | msvc_helper | MSVC |
| 649 | `0x140071990` | 239 | sprite_helper | sprite |
| 650 | `0x1400b6890` | 236 | helper | unnamed |
| 651 | `0x14004a120` | 236 | audio_helper | audio |
| 652 | `0x1400c03a0` | 235 | helper | unnamed |
| 653 | `0x140009f80` | 235 | physics_helper | physics |
| 654 | `0x1402d1900` | 234 | msvc_helper | MSVC |
| 655 | `0x1402ce960` | 234 | msvc_helper | MSVC |
| 656 | `0x1401aa890` | 234 | sdl_helper | SDL |
| 657 | `0x140174c40` | 234 | sdl_gpu_helper | SDL_GPU |
| 658 | `0x140197730` | 233 | helper | unnamed |
| 659 | `0x1401c85b0` | 232 | d3d12_helper | D3D12 |
| 660 | `0x14007ad10` | 231 | helper | unnamed |
| 661 | `0x1401a9ef0` | 230 | utf16_helper | UTF-16LE |
| 662 | `0x1400cb670` | 230 | inv_trumpet_helper | `InvTrumpet` |
| 663 | `0x1401ab3d0` | 229 | sdl_helper | SDL |
| 664 | `0x1400b6170` | 229 | helper | unnamed |
| 665 | `0x14005bad0` | 228 | gif_land_handler | `GifLand` (terrain type? secret feature?) |
| 666 | `0x1402da06c` | 227 | msvc_helper | MSVC |
| 667 | `0x140092620` | 227 | helper | unnamed |
| 668 | `0x140082550` | 227 | helper | unnamed |
| 669 | `0x14003f590` | 227 | audio_helper | audio |
| 670 | `0x140010b00` | 227 | physics_helper | physics |
| 671 | `0x1401acdd0` | 225 | sdl_gpu_debug_props | `SDL.gpu.device.create.debugmode/preferlowpower/shaders.spirv` |
| 672 | `0x1400c69c0` | 225 | helper | unnamed |
| 673 | `0x14009c7d0` | 225 | show_stats_screen | `ShowStatsScreen` |
| 674 | `0x1400a32c0` | 224 | helper | unnamed |
| 675 | `0x1402f31e0` | 222 | msvc_helper | MSVC |
| 676 | `0x1402cfa08` | 222 | msvc_helper | MSVC |
| 677 | `0x140100c90` | 220 | helper | unnamed |
| 678 | `0x1400762a0` | 220 | save_helper | save |
| 679 | `0x140075850` | 220 | save_helper | save |
| 680 | `0x140010430` | 220 | physics_world_lock_assert | `IsLocked() == false` |
| 681 | `0x140053730` | 218 | audio_helper | audio |
| 682 | `0x140038f20` | 218 | freak_handler | `Freak` |
| 683 | `0x1402f66e0` | 216 | msvc_helper | MSVC |
| 684 | `0x1400a5e00` | 215 | bad_gxi_logger | `Bad GXI %d` (bad gene index) |
| 685 | `0x1401c86a0` | 214 | d3d12_helper | D3D12 |
| 686 | `0x140107550` | 214 | helper | unnamed |
| 687 | `0x1402ef618` | 213 | msvc_helper | MSVC |
| 688 | `0x140082330` | 213 | wild_horse_helper | wild horse |
| 689 | `0x14000ce00` | 213 | physics_helper | physics |
| 690 | `0x1400a5d20` | 212 | bad_gx_logger | `Bad GX %d` (similar to GXI; alternate error path) |
| 691 | `0x1400cf540` | 211 | helper | unnamed |
| 692 | `0x14004eeb0` | 211 | vorbis_helper | vorbis |
| 693 | `0x1402d7098` | 210 | msvc_helper | MSVC |
| 694 | `0x140083b50` | 210 | tile_helper | tile |
| 695 | `0x1402f6abc` | 208 | msvc_helper | MSVC |
| 696 | `0x1402e6770` | 207 | msvc_helper | MSVC |
| 697 | `0x1401979c0` | 207 | locale_helper | `LC_ALL`, `LC_CTYPE`, `LC_MESSAGES` |
| 698 | `0x140100fc0` | 207 | wild_horse_helper | wild horse |
| 699 | `0x14009c6a0` | 207 | font_helper | font |
| 700 | `0x1402e9cd4` | 205 | msvc_helper | MSVC |
| 701 | `0x1401637d0` | 205 | helper | unnamed |
| 702 | `0x140104b20` | 205 | gain_money_event | `GainMoney` sound (paid by player) |
| 703 | `0x1401c9e50` | 204 | d3d12_helper | D3D12 |
| 704 | `0x1402eebd8` | 203 | msvc_helper | MSVC |
| 705 | `0x14012f790` | 203 | msvc_helper | MSVC |
| 706 | `0x14009f350` | 203 | font_helper | font |
| 707 | `0x14008d2d0` | 202 | string_helper | string |
| 708 | `0x140027470` | 202 | string_helper | string |
| 709 | `0x1400a9290` | 201 | cosmetic_helper | cosmetic |
| 710 | `0x14012ef60` | 200 | helper | unnamed |
| 711 | `0x1401ab560` | 199 | sdl_helper | SDL |
| 712 | `0x140163700` | 199 | helper | unnamed |
| 713 | `0x1400c7720` | 199 | no_record_3 | `No Record!` |
| 714 | `0x1400bf630` | 199 | helper | unnamed |
| 715 | `0x140075320` | 199 | save_helper | save |
| 716 | `0x140042de0` | 198 | audio_helper | audio |
| 717 | `0x140010240` | 198 | physics_helper | physics |
| 718 | `0x1401b54e0` | 197 | sdl_helper | SDL |
| 719 | `0x140016810` | 196 | physics_helper | physics |
| 720 | `0x1402da530` | 195 | msvc_helper | MSVC |
| 721 | `0x1400bf700` | 195 | helper | unnamed |
| 722 | `0x1402e9b78` | 193 | msvc_helper | MSVC |
| 723 | `0x140067490` | 193 | pause_button_widget | pause-menu button |
| 724 | `0x140037420` | 193 | helper | unnamed |
| 725 | `0x1400c9f10` | 189 | helper | unnamed |
| 726 | `0x1401cbb30` | 188 | d3d12_helper | D3D12 |
| 727 | `0x14012e790` | 188 | helper | unnamed |
| 728 | `0x1400c6d00` | 188 | rng_helper | rng |
| 729 | `0x14004f150` | 187 | audio_helper | audio |
| 730 | `0x1402f4ed4` | 186 | msvc_helper | MSVC |
| 731 | `0x1401885b0` | 185 | sofile_loader | `UTF-16LE`, `sofile` (shared-object loader) |
| 732 | `0x140027750` | 184 | string_helper | string |
| 733 | `0x1400128b0` | 184 | physics_helper | physics |
| 734 | `0x1402d0290` | 183 | msvc_helper | MSVC |
| 735 | `0x1400dc2d0` | 183 | helper | unnamed |
| 736 | `0x1402d7230` | 182 | msvc_helper | MSVC |
| 737 | `0x1402cd39c` | 182 | msvc_helper | MSVC |
| 738 | `0x1400cca50` | 182 | helper | unnamed |
| 739 | `0x1402e8544` | 181 | msvc_helper | MSVC |
| 740 | `0x1402e0598` | 181 | msvc_helper | MSVC |
| 741 | `0x1401c9630` | 181 | d3d12_helper | D3D12 |
| 742 | `0x1402d8ca8` | 179 | msvc_helper | MSVC |
| 743 | `0x1401aaee0` | 179 | sdl_helper | SDL |
| 744 | `0x1400a3200` | 179 | xml_helper | xml |
| 745 | `0x1402ece80` | 177 | msvc_helper | MSVC |
| 746 | `0x1402d8a8c` | 177 | msvc_helper | MSVC |
| 747 | `0x140044ff0` | 177 | audio_helper | audio |
| 748 | `0x1400124f0` | 177 | physics_helper | physics |
| 749 | `0x1402d3908` | 176 | msvc_helper | MSVC |
| 750 | `0x1400c9fe0` | 176 | helper | unnamed |
| 751 | `0x1402eaf4c` | 175 | msvc_helper | MSVC |
| 752 | `0x140005960` | 175 | physics_alpha_assert | `alpha0 < 1.0f` |
| 753 | `0x1402e93d0` | 174 | msvc_helper | MSVC |
| 754 | `0x1400d8d00` | 174 | render_helper | render |
| 755 | `0x1400b8720` | 174 | helper | unnamed |
| 756 | `0x140067270` | 174 | pause_helper | pause |
| 757 | `0x1401753d0` | 173 | sdl_helper | SDL |
| 758 | `0x140142b00` | 173 | helper | unnamed |
| 759 | `0x14006f4e0` | 173 | save_helper | save |
| 760 | `0x14004f0a0` | 173 | audio_helper | audio |
| 761 | `0x1401aaff0` | 171 | sdl_table | `table` |
| 762 | `0x1402d3580` | 170 | msvc_helper | MSVC |
| 763 | `0x140012800` | 170 | physics_size_assert | `0 < size` |
| 764 | `0x1400b2e30` | 169 | helper | unnamed |
| 765 | `0x1400471e0` | 169 | audio_helper | audio |
| 766 | `0x1402d1ca8` | 168 | msvc_helper | MSVC |
| 767 | `0x1400a8680` | 168 | helper | unnamed |
| 768 | `0x14009bcc0` | 168 | helper | unnamed |
| 769 | `0x1402c8240` | 167 | msvc_helper | MSVC |
| 770 | `0x140081600` | 166 | wild_horse_helper | wild horse |
| 771 | `0x1402ce1e0` | 165 | msvc_helper | MSVC |
| 772 | `0x1400bf070` | 165 | helper | unnamed |
| 773 | `0x14006ffa0` | 165 | sprite_helper | sprite |
| 774 | `0x14000cee0` | 165 | physics_helper | physics |
| 775 | `0x1400ca150` | 164 | helper | unnamed |
| 776 | `0x1400641d0` | 164 | helper | unnamed |
| 777 | `0x14005e310` | 164 | helper | unnamed |
| 778 | `0x1402f0358` | 163 | msvc_helper | MSVC |
| 779 | `0x140100d80` | 163 | wild_horse_helper | wild horse |
| 780 | `0x1400ce9b0` | 163 | helper | unnamed |
| 781 | `0x140074460` | 163 | sprite_helper | sprite |
| 782 | `0x1400262c0` | 163 | xml_helper | xml |
| 783 | `0x1402f7f1c` | 162 | msvc_helper | MSVC |
| 784 | `0x1402ed0c0` | 162 | msvc_helper | MSVC |
| 785 | `0x1401ab7a0` | 162 | sdl_helper | SDL |
| 786 | `0x140012970` | 162 | physics_helper | physics |
| 787 | `0x1402d185c` | 161 | msvc_helper | MSVC |
| 788 | `0x140024b40` | 161 | string_helper | string |
| 789 | `0x14008d150` | 160 | string_helper | string |
| 790 | `0x14004cee0` | 160 | vorbis_helper | vorbis |
| 791 | `0x140025e00` | 160 | xml_helper | xml |
| 792 | `0x1402e08a8` | 159 | msvc_helper | MSVC |
| 793 | `0x1400aabb0` | 159 | helper | unnamed |
| 794 | `0x14008d0a0` | 158 | string_helper | string |
| 795 | `0x140075f20` | 158 | save_helper | save |
| 796 | `0x140005e10` | 158 | physics_lock_assert | `IsLocked() == false` |
| 797 | `0x1400c8dc0` | 157 | helper | unnamed |
| 798 | `0x1402d15ac` | 156 | msvc_helper | MSVC |
| 799 | `0x140010c10` | 156 | physics_bodies_assert | `def->bodyA != def->bodyB` |
| 800 | `0x1402cea4c` | 155 | msvc_helper | MSVC |
| 801 | `0x1402ce7c8` | 155 | msvc_helper | MSVC |
| 802 | `0x1402cdfa0` | 155 | sqrtf_helper | `sqrtf` |
| 803 | `0x1402cd300` | 155 | msvc_helper | MSVC |
| 804 | `0x1400c5580` | 155 | string_helper | string |
| 805 | `0x1400bf150` | 155 | helper | unnamed |
| 806 | `0x1400befd0` | 155 | struct_init_18 | zero-inits 18 fields |
| 807 | `0x140087ec0` | 155 | string_helper | string |
| 808 | `0x140067e60` | 155 | location_init_3 | zero-inits 3 fields |
| 809 | `0x1402eb16c` | 154 | msvc_helper | MSVC |
| 810 | `0x1402eb0c8` | 154 | msvc_helper | MSVC |
| 811 | `0x1402ed000` | 153 | msvc_helper | MSVC |
| 812 | `0x1402d72e8` | 153 | wchar_helper | wchar_t string helper |
| 813 | `0x140174d30` | 153 | sdl_helper | SDL |
| 814 | `0x1400642e0` | 153 | helper | unnamed |
| 815 | `0x140037380` | 153 | helper | unnamed |
| 816 | `0x1402db0a8` | 152 | msvc_helper | MSVC |
| 817 | `0x1402cf00c` | 152 | msvc_helper | MSVC |
| 818 | `0x1402ce288` | 152 | msvc_helper | MSVC |
| 819 | `0x1400a58b0` | 151 | xml_helper | xml |
| 820 | `0x1400766f0` | 149 | save_helper | save |
| 821 | `0x1401c5df0` | 148 | d3d12_helper | D3D12 |
| 822 | `0x140174dd0` | 148 | sdl_helper | SDL |
| 823 | `0x140101220` | 148 | wild_horse_helper | wild horse |
| 824 | `0x14000e340` | 148 | physics_helper | physics |
| 825 | `0x140008300` | 148 | physics_helper | physics |
| 826 | `0x1401c42c0` | 146 | d3d12_helper | D3D12 |
| 827 | `0x140075940` | 146 | save_helper | save |
| 828 | `0x140175500` | 145 | sdl_helper | SDL |
| 829 | `0x14009bb10` | 145 | helper | unnamed |
| 830 | `0x1402f3150` | 144 | msvc_helper | MSVC |
| 831 | `0x1402e86c4` | 144 | msvc_helper | MSVC |
| 832 | `0x1401ab340` | 144 | sdl_table | `table` |
| 833 | `0x14012df60` | 144 | msvc_helper | MSVC |
| 834 | `0x14004f010` | 143 | audio_helper | audio |
| 835 | `0x1402d3e44` | 141 | msvc_helper | MSVC |
| 836 | `0x1402ceae8` | 141 | msvc_helper | MSVC |
| 837 | `0x14009f5e0` | 141 | font_helper | font |
| 838 | `0x1400273e0` | 141 | string_helper | string |
| 839 | `0x1402e9480` | 140 | msvc_helper | MSVC |
| 840 | `0x1402e9320` | 140 | msvc_helper | MSVC |
| 841 | `0x1402e1948` | 140 | msvc_helper | MSVC |
| 842 | `0x1400c7560` | 140 | string_helper | string |
| 843 | `0x1400d8c70` | 139 | render_helper | render |
| 844 | `0x140040ee0` | 139 | sound_helper | sound |
| 845 | `0x1402d19ec` | 138 | msvc_helper | MSVC |

---

**Cumulative coverage: 845 of 1,234 game-logic functions = 68.5%.**

New specific finds:
- `0x140038f20`: freak_handler (`Freak` - circus freak tent reference)
- `0x1400a5e00/1400a5d20`: Bad-Gene-Index loggers (two paths)
- `0x140104b20`: gain_money_event (`GainMoney` sound)
- `0x14005bad0`: gif_land_handler (`GifLand` — possibly an animated terrain tile?)
- `0x14009c7d0`: show_stats_screen (`ShowStatsScreen`)
