cmake_minimum_required(VERSION 3.17)
project(TypingSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(TypingSFML main.cpp Typing.cpp Typing.h Fonts.cpp Fonts.h MultiText.cpp MultiText.h Letter.cpp Letter.h Node.h Node_Iterator.cpp Node_Iterator.h LinkedList.h LinkedList.cpp EventHandler.cpp EventHandler.h ObjectStates.h Snapshot.cpp Snapshot.h SnapshotInterface.cpp SnapshotInterface.h States.cpp States.h MouseEvents.cpp MouseEvents.h GUI_Component.cpp GUI_Component.h TextInput.cpp TextInput.h TextBox.cpp TextBox.h Label.cpp Label.h Cursor.cpp Cursor.h History.cpp History.h KeyShortcuts.cpp KeyShortcuts.h Coloring.cpp Coloring.h HistoryNode.h Item.cpp Item.h ItemList.cpp ItemList.h InputBox.cpp InputBox.h DropdownMenu.cpp DropdownMenu.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h FileItem.cpp FileItem.h Image.cpp Image.h FileNode.cpp FileNode.h FileTree.cpp FileTree.h Slider.cpp Slider.h Logo.cpp Logo.h LogoMaker.cpp LogoMaker.h ColorGradient.cpp ColorGradient.h ColorBox.cpp ColorBox.h ColorOption.cpp ColorOption.h ColorPicker.cpp ColorPicker.h WindowDialog.cpp WindowDialog.h)

target_link_libraries(TypingSFML sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)