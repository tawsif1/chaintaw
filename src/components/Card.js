import React, {useCallback} from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import CardMedia from '@material-ui/core/CardMedia';
import Button from '@material-ui/core/Button';
import Typography from '@material-ui/core/Typography';

const useStyles = makeStyles({
    root: {
        // maxWidth: 345,
    },
});

export default function ImgMediaCard() {
    const classes = useStyles();
  
   
    

    return (
        <Card className={classes.root} >
            <CardActionArea>
                <CardMedia
                    component="img"
                    alt="Contemplative Reptile"
                    height="140"
                    image="https://img2.carmax.com/img/vehicles/19338037/1/400.jpg"
                    title="Contemplative Reptile"
                />
                <CardContent>
                    <Typography gutterBottom variant="h5" component="h2">
                        2017 RC 350
                    </Typography>
                    <Typography variant="body2" color="textSecondary" component="p">
                        Lexus
                    </Typography>
                    <Typography variant="subtitle1" color="primary" component="p">
                        <strike>$27,533</strike> $20,000
                    </Typography>
                </CardContent>
            </CardActionArea>
            <CardActions>
                <Button size="small" color="primary">
                    Buy
                </Button>
            </CardActions>
        </Card>
    );
}
