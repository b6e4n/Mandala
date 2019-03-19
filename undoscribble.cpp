#include "undoscribble.h"

UndoScribble::UndoScribble()
{

}

void UndoScribble::undo(){
    object->setVersion(old_scribble);  //setVersion fonction de la classe ScribbleArea qui prend en parametre
    //une version de lui même stoké sur une stackUndo et le reprojette à l'écran
}

void UndoScribble::redo(){
    object->setVersion(new_scribble);
}


void UndoScribble::id(){   //identifie un type d'action par un entier.
                          //ici action sur le scribblearea est identifié par 1 (choisi arbitrairement)
    return 1;
}

bool UndoScribble::mergeWith(const QUndoCommand *cmd){ //regroupe des actions de meme types
    if(cmd->type()!=1){
        return false;
    }
    const UndoScribble *undo_scribble=static_cast<const UndoScribble*>(cmd); //recuperer pointeur vers l'undoScribble
    if(undo_scribble->object!=object){ //on verifie si il s'agit du meme objet
        return false;
    }
    new_scribble=cmd->new_scribble;
    return true;
}



/*
 * A definir dans la classe ScribbleArea
 *
 * private QUndoStack undo_stack;
 *
 * public ScribbleArea::setVersion(QWidget new){
 *     UndoScribble *undo_scribble=new UndoScribble(this,get_old_scribble(),new) //get_old_scribble va chercher sur la pile l'ancienne version de scribble
 *     undo_stack->push(cmd);
 * }
 *
 *
 * private ScribbleArea::setVersion(Qwidget new){ //fonction qui agit sur la classe parente du widget ScribbleArea
 * }
