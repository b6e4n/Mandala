#ifndef UNDOSCRIBBLE_H
#define UNDOSCRIBBLE_H


class UndoScribble : public QUndoCommand
{
    Q_OBJECT
public:
    UndoScribble();
    void undo();
    void redo();
    void id();
    bool mergeWith(const QUndoCommand *cmd);

private:
    QImage *old_scribble; //ancienne version du dessin
    QImage *new_scribble; //actuelle version de dessin
    ScribbleArea *object;  //Nom de la classe de dessin
};

#endif // UNDOSCRIBBLE_H
